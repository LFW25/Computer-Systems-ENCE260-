/* Include statements*/
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <ctype.h>
# include "signMag.h"

SignMag_t* arrayMax(SignMag_t* array, size_t size, bool (*func)(SignMag_t*, SignMag_t*, SignMag_t**))
{
    SignMag_t* currentMax = &(array[0]);
    for (size_t i = 0; i < size; i++) {
        (*func)(&(array[i]), &(*currentMax), &currentMax);
    }
    return currentMax;
}

int main(void)
{
    /* Read in an array of SignMag_t values until an invalid thing (e.g. quit) is entered
        or until the array hits a maximum of 100 values */
    size_t arraySize = 0;
    SignMag_t fullArray[100];
    SignMag_t newSM;
    do {
        newSM = signMag_read();
        if (((newSM.magnitude == 0) && (newSM.isNegative == true)) || (arraySize >= 100)) {
            break;
        } else {
            fullArray[arraySize] = newSM;
        }
        arraySize++;
    } while (arraySize < 100);

    SignMag_t culledArray[arraySize];

    /* Print out the array of values, one per line, using signMag_print() */
    for(uint8_t i = 0; i < arraySize; i++) {
        printf("Got Number: ");
        signMag_print(fullArray[i]);
        culledArray[i] = fullArray[i];
    }

    /* Compute the accumulated sum of the values in the array using signMag_accumulate()
        and print using the signMag_print() */
    printf("Accumulated Sum: ");
    SignMag_t accumSum = signMag_accumulate(culledArray, arraySize);
    signMag_print(accumSum);

    /* Compute and print the square of the accumulated sum using signMag_multiply()
        and print using signMag_print() */
    printf("Square Accumulated Sum: ");
    signMag_print(signMag_multiply(accumSum, accumSum));

    /* Find the maximum value in the array using arrayMax() together with signMag_max()
        and print using signMag_print() */
    printf("Max of Numbers: ");
    signMag_print(*(arrayMax(culledArray, arraySize, &signMag_max)));
}