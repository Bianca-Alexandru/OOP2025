#include "Seat.h"
#include <cstring>  

Seat::Seat() {
    fuelCapacity = 50;
    fuelConsumption = 7;
    avgSpeed[0] = 75;
    avgSpeed[1] = 110;
    avgSpeed[2] = 60;
    strcpy_s(name, sizeof(name), "Seat");
}

float Seat::GetSpeed(Weather condition) {
    if (condition == Weather::Rain)
        return avgSpeed[0];
    if (condition == Weather::Sunny)
        return avgSpeed[1];
    if (condition == Weather::Snow)
        return avgSpeed[2];
}

float Seat::GetFuelCapacity() {
    return fuelCapacity;
}

float Seat::GetFuelConsumption() {
    return fuelConsumption;
}

const char* Seat::GetName() {
    return name;
}
