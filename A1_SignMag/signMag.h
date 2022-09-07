# ifndef SIGNMAG_H
# define SIGNMAG_H

/* Include statements*/
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <ctype.h>

/* Define the SignMag_t datatype */
/*'isNegative' - A bool to represent the sign of the number */
/*'magnitude' - An unsigned 16-bit integer value*/

typedef struct {
    bool isNegative;
    uint16_t magnitude;
} SignMag_t;

/* Define functions */

/* signMag_init: Initialises a new SignMag_t value */
SignMag_t signMag_init(bool isNegative, uint16_t magnitude);

/* signMag_print: Prints a SignMag_t value */
void signMag_print(SignMag_t value);

/* signMag_read: Takes an input to make a new SignMag_t value */
SignMag_t signMag_read(void);

/* signMag_sum: Adds two SignMag_t values together */
SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2);

/* signMag_accumulate: Sums an array of SignMag_t values */
SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize);

/* signMag_multiply: Multiplies two SignMag_t values */
SignMag_t signMag_multiply(SignMag_t num1, SignMag_t num2);

/* signMag_max: Finds the maximum of two sign magnitude values */
bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max);

# endif //SIGNMAG_H