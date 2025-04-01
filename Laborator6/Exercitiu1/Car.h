#pragma once
#include "Weather.h"

class Car {
protected:
    float fuelCapacity;    
    float fuelConsumption; 
    float avgSpeed[3];    
    char name[20];      

public:
    virtual ~Car() {}  

    virtual float GetSpeed(Weather condition) = 0;
    virtual float GetFuelCapacity() = 0;
    virtual float GetFuelConsumption() = 0;
    virtual const char* GetName() = 0;
};
