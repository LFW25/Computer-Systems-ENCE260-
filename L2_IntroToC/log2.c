# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
 
uint8_t intLog2(uint32_t value)
{
    uint8_t i = 0;
    while (value > 1) {
        value = value / 2;
        i++;
    }
    return i;
}

int main(void)
{
    printf("%d\n", intLog2(32));
    printf("%d\n", intLog2(31));
}
