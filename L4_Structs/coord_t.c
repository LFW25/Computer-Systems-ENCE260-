# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>


typedef struct {
    float lat;
    float lon;
    float alt;
} Coord_t;

bool isBelowSeaLevel(const Coord_t coord)
{
    return(coord.alt < 0);
}

uint64_t numBelowSeaLevel(const Coord_t coords[], size_t n)
{
    uint8_t count = 0;
    
    for (size_t i = 0; i <= n; i++) {
        if (coords[i].alt < 0) {
            count++;
        }
    }
    return count;
}

int main(void) {
    Coord_t everest = {
        .lat = 27.988056,
        .lon = 86.925278,
        .alt = 8848.86
    };
    printf(isBelowSeaLevel(everest) ? "true\n" : "false\n");

    Coord_t coords[5];
    for (size_t i = 0; i < 5; i++) {
        coords[i].lat = ((float)i - 2)*15;
        coords[i].lon = ((float)i - 2)*-15;
        coords[i].alt = ((float)i - 2)*100;
    }
    printf("%ld\n", numBelowSeaLevel(coords, 5));
}
