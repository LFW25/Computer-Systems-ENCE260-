# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

int main(void)
{
    size_t n = 10;
    int16_t* array = calloc(n, sizeof(int16_t));
    int16_t inpNum;
    size_t i = 0;
    do {
        scanf("%hd", &inpNum);
        if (inpNum != -10000) {
            if (i < n-1) {
                array[i] = inpNum;
            } else {
                n += 10;
                array = realloc(array, n*sizeof(int16_t));
                array[i] = inpNum;
            }
            i++;
        } 
    } while (inpNum != -10000);

    printf("Numbers read = %ld\n", i);
    free(array);
}