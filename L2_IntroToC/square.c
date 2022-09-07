# include <stdio.h>
# include <stdint.h>

uint64_t square(int32_t x)
{
    return x*x;
}

void printNumber(int32_t x)
{
    printf("%d\n", x);
}

int main(void)
{
    printf("%lu\n", square(3));
    printNumber(7);
}
