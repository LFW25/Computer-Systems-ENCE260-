#include <stdio.h>
#include <stdint.h>

void printSquaredArray(const int32_t array[], size_t n)
{
    size_t i;
    int32_t elem;
    for (i = 0; i < n; i++) {
        elem = array[i];
        printf("%d\n", elem*elem);
    }
}

int main(void)
{
    const int32_t array[3] = {1, 2, 3};
    printSquaredArray(array, 3);
}
