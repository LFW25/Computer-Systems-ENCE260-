#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf("Hello World!\n");
    for (uint8_t i = 0; i < 100; i++) {
        printf("%d\n", i);
    }
}