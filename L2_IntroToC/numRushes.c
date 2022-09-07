# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
 
uint32_t countRushes(float screeHeight, float rushHeight, float slideBack)
{
    float height = 0;
    uint32_t numRushes = 0;
    while (height < screeHeight) {
        height += rushHeight;
        numRushes++;
        if (height >= screeHeight) {
            return numRushes;
        } else {
            height -= slideBack;
        }
    }
    return numRushes;
}

int main(void)
{
    printf("%d\n", countRushes(100, 50, 10));
    printf("%d\n", countRushes(100, 100, 90));
    printf("%d\n", countRushes(0, 100, 30));
    printf("%d\n", countRushes(1.0, 0.5, 0.1));

}
