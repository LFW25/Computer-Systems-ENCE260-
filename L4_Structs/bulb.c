# include <stdint.h>
# include <stdio.h>
# include "bulb.h"

static uint64_t bulbs [256] = {0};

Bulb_t bulb_sellModel(uint8_t model)
{
  
    Bulb_t newBulb = {model, bulbs[model]};
    bulbs[model] += 1;  

    return newBulb;
}

void bulb_display(Bulb_t bulb)
{
    printf("Model %hhu, SN%06lu\n", bulb.model, bulb.serialNumber);
}

uint64_t bulb_numSold(uint8_t model)
{
    return bulbs[model];
}

