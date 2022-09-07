#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int32_t index2d(int32_t* array, size_t width, size_t i, size_t j)
{
    int32_t retnum = 0;
    retnum = *(array + (i * width + j));
    return (retnum);
}

int main(void)
{
    int32_t array1[2][3] = {{1, 2, 3}, 
                           {4, 5, 6}};
    printf("%d\n", index2d((int32_t*)array1, 3, 0, 1));

    int32_t array2[2][4] = {{1, 2, 3, 4}, 
                            {2, 4, 6, 8}};
    printf("%d\n", index2d((int32_t*)array2, 4, 0, 3));

    int32_t array3[3][2] = {{1, 2}, 
                            {2, 4},
                            {8, 3}};
    printf("%d\n", index2d((int32_t*)array3, 2, 2, 1));
}
