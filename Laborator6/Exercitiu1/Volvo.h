#pragma once
#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    float GetSpeed(Weather condition);
    float GetFuelCapacity();
    float GetFuelConsumption();
    const char* GetName();
};
