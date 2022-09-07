#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "temp.h"

static float fToC(float fahr)
{
    float cel = 0;
    cel = (fahr - 32)/(1.8);
    return cel;
}

static float cToF(float cel)
{
    float fahr = 0;
    fahr = (cel * (1.8)) + 32;
    return fahr;
}

static float cToK(float cel)
{
    float kev = 0;
    kev = cel + 273.15;
    return kev;
}

static float kToC(float kev)
{
    float cel = 0;
    cel = kev - 273.15;
    return cel;
}


static Temp_t convert(Temp_t temp, Unit_t toUnit)
{
    float newValue = temp.temperature;
    Unit_t newUnit = toUnit;

    if (temp.tUnit == CELSIUS) {
        if (toUnit == FAHRENHEIT) {
            newValue = cToF(temp.temperature);
            printf("%.2f deg F\n", newValue);
        } else if (toUnit == CELSIUS) {
            printf("%.2f deg C\n", temp.temperature);
        } else {
            newValue = cToK(temp.temperature);
            printf("%.2f K\n", newValue);
        }      
    } else if (temp.tUnit == FAHRENHEIT) {
        if (toUnit == CELSIUS) {
            newValue = fToC(temp.temperature);
            printf("%.2f deg C\n", newValue);
        } else if (toUnit == FAHRENHEIT) {
            printf("%.2f deg F\n", temp.temperature);
        } else {
            newValue = cToK(fToC(temp.temperature));
            printf("%.2f K\n", newValue);
        }        
    } else {
        if (toUnit == CELSIUS) {
            newValue = kToC(temp.temperature);
            printf("%.2f deg C\n", newValue);
        } else if (toUnit == KELVIN) {
            printf("%.2f K\n", temp.temperature);
        } else {
            newValue = cToF(kToC(temp.temperature));
            printf("%.2f deg F\n", newValue);
        }
    }
    Temp_t newTemp = {newValue, newUnit};
    return newTemp;
}


void temp_set(Temp_t* temp, float value, Unit_t unit)
{
    temp->temperature = value;
    temp->tUnit = unit;
}

void temp_print(const Temp_t* temp, Unit_t unit)
{
    convert(*temp, unit);
}

