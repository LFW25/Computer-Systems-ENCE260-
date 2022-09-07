# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>


struct PolarVec_s {
    uint32_t radius;
    float angle;
};

struct PolarVec_s initPolarVec(uint32_t radius, float angle)
{
    struct PolarVec_s newVec;
    newVec.radius = radius;
    newVec.angle = angle;
    return(newVec);
}

void printPolarVec(struct PolarVec_s v)
{
    printf("%.1d : %.1f\n", v.radius, v.angle);
}

int main(void) {
    struct PolarVec_s v = initPolarVec(1, 180);
    printPolarVec(v);
}
