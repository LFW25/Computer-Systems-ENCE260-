#include <stdio.h>
#include <stdint.h>

void printArray(int32_t* array, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
}

int main(void)
{
    int32_t array[100] = {0};
    int8_t i = 0;
    int32_t inp;
    
    do {
        scanf("%d", &inp);
        array[i] = inp;
        if (inp != -1) {
            i++;
        }
    } while ((inp != -1) && (i < 100));

    printf("%d numbers entered\n", i);
    printArray(array, i);
}
