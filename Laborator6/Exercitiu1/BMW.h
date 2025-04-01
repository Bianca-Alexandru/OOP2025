#pragma once
#include "Car.h"

class BMW : public Car {
public:
    BMW();
    float GetSpeed(Weather condition) ;
    float GetFuelCapacity() ;
    float GetFuelConsumption() ;
    const char* GetName() ;
};
