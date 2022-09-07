# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include "lift.h"

Lift_t lift_init(uint8_t maxPassengers, int16_t startFloor)
{
    Lift_t newLift = {startFloor, 0, maxPassengers};
    return newLift;
}

void lift_onboard(Lift_t* lift, uint8_t peopleOff, uint8_t peopleOn)
{
    lift->numPassengers += (peopleOn - peopleOff);
}

int16_t lift_goToFloor(Lift_t* lift, int16_t floor)
{
    if (lift->numPassengers <= lift->passengerLimit) {
        lift->currentFloor = floor;
    }
    return lift->currentFloor;
}

