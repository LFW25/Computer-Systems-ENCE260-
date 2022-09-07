# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>

typedef enum {
    REVERSE = -1,
    NEUTRAL = 0,
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
} Gear_t;

int main(void) {
    Gear_t currentGear = FIRST;
    printf("%d\n", currentGear + THIRD);
}
