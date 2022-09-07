#include <stdio.h>
#include <stdint.h>

int32_t accumulator(int32_t value)
{
    static int32_t accumulator_sum = 0;
    accumulator_sum += value;
    return accumulator_sum;
}

void swap(uint8_t* address1, uint8_t* address2)
{
    uint8_t temp;
    temp = *address1;
    *address1 = *address2;
    *address2 = temp;
}

void convertDistance(const double* metres, double* centimetres, double* kilometres)
{
    *centimetres = *metres*100;
    *kilometres = *metres/1000;
}

int main(void)
{
    const double metres = 100;
    double centimetres = 0;
    double kilometres = 0;
    convertDistance(&metres, &centimetres, &kilometres);
    printf("%.1e m, %.1e cm, %.1e km\n", metres, centimetres, kilometres);
}
