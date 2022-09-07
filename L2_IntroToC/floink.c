# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
 
int32_t gringe(int32_t boink, int32_t flunk)
{
    // *** what single line should go here? ***
    return boink == flunk ? 42 : flunk - 11;
}

int main(void)
{
    printf("%d\n", gringe(23, 23));
    printf("%d\n", gringe(23, 24));

}
