/* Include statements*/
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <ctype.h>
# include "signMag.h"

/* Define functions
    signMag_init:
        Initialises a new SignMag_t value
            Signature: SignMag_t signMag_init(bool isNegative, uint16_t magnitude)
        
    signMag_print:
        Prints a SignMag_t value.
        Negative numbers (isNegative = True) are printed with a -,
        Positive numbers (isNegative = False) have no prefix.
            Signature: void signMag_print(SignMag_t value)
    
    signMag_read:
        Reads a SignMag_t value and determines legitimacy.
        A legitimate value may have a -, +, or no prefix
        followed by digits 0-9 (base 10).

        An illegitimate symbol includes a space, a \n, or an EOF
        and will not be converted into a SignMag_t type, instead
        return -0.

        If the input is greater than the maximum magnitude (>65535),
        returns 65535.

            Signature: SignMag_t signMag_read(void)
    
    signMag_sum:
        Adds two sign magnitude values and returns the summation.
        Saturation arithmetic must be used, so if the summed magnitude
        is greater than 65535, 65535 must be the returned magnitude.

            Signature: SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2)
    
    signMag_accumulate:
        Accumulates and array of SignMag_t values.
        The return value is the summation of all the values in the array.
        Saturation arithmetic must be used.

            Signature: SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize)
    signMag_max:
        Finds the maximum of two SignMag_t values.
        Returns True if the magnitude of either value is maximum (65535).
        *max should be a pointer to the address of the higher value.

            Signature: bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max)
*/

SignMag_t signMag_init(bool isNegative, uint16_t magnitude)
{
    SignMag_t newValue = {isNegative, magnitude};
    return newValue;
}

void signMag_print(SignMag_t value)
{
    if (value.isNegative == 1) {
        printf("-");
    }

    printf("%d\n", value.magnitude);
}

SignMag_t signMag_read(void)
{
    char c;
    bool isNeg = 0;
    uint8_t i = 0;
    uint64_t num = -1;

    c = getchar();
    if (isdigit(c) || ((c == '-') || (c == '+'))) {
        /* printf("First char is a digit or a valid prefix.\n"); */
        i++;
        if (c == '-') {
            isNeg = 1;
        }
    }

    while (((isdigit(c)) || (c == '-') || (c == '+')) && (i > 0)) {
        /* printf("Old Number: %ld\n", num);
        printf("Digit: %c\n", c); */
        if (num == -1) {
            /* printf("This must be the first digit or the prefix.\n"); */
            num = 0;
        }
        if (isdigit(c)) {
            /* printf("This is a digit!\n"); */
            num = (c - '0') + (10 * num);
            /* printf("New Number: %ld\n", num); */
        }/* else {
            printf("This is a prefix.\n");
        } */
        c = getchar();
        i++;
    }
    /* printf("While loop has exited.\n"); */
    if (num == -1) {
        num = 0;
        isNeg = 1;
        /* printf("It has detected that the program is invalid.\n"); */
    } else if (num > 65535) {
        /* printf("Overflow.\n"); */
        num = 65535;
    }
    
    SignMag_t newMag;
    newMag = signMag_init(isNeg, num);
    return newMag;
}

SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2)
{
    bool isNeg = 0;
    uint64_t newMag = 0;

    if (sm1.isNegative == sm2.isNegative) {
        isNeg = sm1.isNegative;
        newMag = sm1.magnitude + sm2.magnitude;    
    } else {
        if (sm1.magnitude > sm2.magnitude) {
            newMag = sm1.magnitude - sm2.magnitude;
            if (sm1.isNegative == 1) {
                isNeg = 1;
            } else {
                isNeg = 0;
            }
        } else {
            newMag = sm2.magnitude - sm1.magnitude;
            if (sm2.isNegative == 1) {
                isNeg = 1;
            } else {
                isNeg = 0;
            }
        }
    }

    if (newMag > 65535) {
        newMag = 65535;
    }

    SignMag_t newSignMag;
    newSignMag = signMag_init(isNeg, newMag);

    return newSignMag;
}

SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize)
{
    uint8_t i = 0;
    SignMag_t accumulatedSignMag = {0, 0};

    for (i = 0; i < arraySize; i++) {
        accumulatedSignMag = signMag_sum(accumulatedSignMag, array[i]);
    }

    return accumulatedSignMag;
}

bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max)
{
    if ((num1->isNegative == 0) && (num2->isNegative == 0)) {
        if (num1->magnitude >= num2->magnitude) {
            *max = num1;
        } else {
            *max = num2;
        }
    } else if (num1->isNegative != num2->isNegative) {
        if (num1->isNegative == 0) {
            *max = num1;
        } else {
            *max = num2;
        }
    } else {
        if (num1->magnitude <= num2->magnitude) {
            *max = num1;
        } else {
            *max = num2;
        }
    }



    if ((num1->magnitude == 65535) || (num2->magnitude == 65535)) {
        return true;
    } else {
        return false;
    }
}

