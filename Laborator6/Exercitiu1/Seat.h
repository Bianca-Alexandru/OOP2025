#pragma once
#include "Car.h"

class Seat : public Car {
public:
    Seat();
    float GetSpeed(Weather condition);
    float GetFuelCapacity();
    float GetFuelConsumption();
    const char* GetName();
};
