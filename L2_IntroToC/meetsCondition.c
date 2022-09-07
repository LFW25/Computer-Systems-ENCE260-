# include <stdio.h>
# include <stdint.h>

void meetsCondition(int64_t x)
{
    if (((x % 2 == 0) && (x >= 0)) || ((x < 0) && (x % 2 != 0))) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main(void)
{
    meetsCondition(0);
    meetsCondition(-2);
    return 0;
}
