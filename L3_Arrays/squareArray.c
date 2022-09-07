#include <stdio.h>
#include <stdint.h>

void squareArray(int32_t array[], size_t n)
{
    size_t i;
    int32_t elem;
    for (i = 0; i < n; i++) {
        elem = array[i];
        elem = elem*elem;
        array[i] = elem;
    }
}

int main(void)
{
    int32_t array[3] = {1, 2, 3};
    squareArray(array, 3);
    printf("%d\n", array[0]);
    printf("%d\n", array[1]);
    printf("%d\n", array[2]);
}
