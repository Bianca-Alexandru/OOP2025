#pragma once
#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    float GetSpeed(Weather condition);
    float GetFuelCapacity();
    float GetFuelConsumption();
    const char* GetName();
};
