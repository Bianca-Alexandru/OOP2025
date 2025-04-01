#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    float GetSpeed(Weather condition);
    float GetFuelCapacity();
    float GetFuelConsumption();
    const char* GetName();
};
