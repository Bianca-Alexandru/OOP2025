#include "RangeRover.h"
#include <cstring>  

RangeRover::RangeRover() {
    fuelCapacity = 80;
    fuelConsumption = 12;
    avgSpeed[0] = 90;
    avgSpeed[1] = 140;
    avgSpeed[2] = 75;
    strcpy_s(name, sizeof(name), "RangeRover");
}

float RangeRover::GetSpeed(Weather condition) {
    if (condition == Weather::Rain)
        return avgSpeed[0];
    if (condition == Weather::Sunny)
        return avgSpeed[1];
    if (condition == Weather::Snow)
        return avgSpeed[2];
}

float RangeRover::GetFuelCapacity() {
    return fuelCapacity;
}

float RangeRover::GetFuelConsumption() {
    return fuelConsumption;
}

const char* RangeRover::GetName() {
    return name;
}
