#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <ctype.h>

void readInput(int64_t* numArray)
{
    uint8_t i;

    for (i = 0; i < 10; ++i) {
        scanf("%ld", &(numArray[i]));
    }
}

int compar(const void * numOne, const void * numTwo)
{  
    uint64_t val1 = *(uint64_t*)numOne;
    uint64_t val2 = *(uint64_t*)numTwo;    

    if (val1 > val2) {
        return 1;
    } else if (val1 == val2) {
        return 0;
    } else {
        return -1;
    }

    
}


int main(void)
{
    int64_t numArray[10];
    readInput(numArray);
    qsort(numArray, 10, sizeof(int64_t), compar);
    
    uint8_t j;
    for (j = 0; j < 10; j++) {
        printf("%ld\n", numArray[j]);
    }
}
