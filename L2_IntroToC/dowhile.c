# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
 
uint8_t doWhile(void)
{
    uint8_t i = 0;
    char c;
    do {
        c = getchar();
        i = i + 1;
    } while (c != 'q');
    return i;
}

int main(void)
{
    printf("%d\n", doWhile());
}
