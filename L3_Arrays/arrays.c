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
    int32_t array[3] = {1, 2, 3};
    printArray(array, 3);
}
