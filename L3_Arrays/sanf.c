#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t num1;
    int32_t num2;
    int32_t sum;
    
    sum = scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    printf("%d\n", sum);
}
