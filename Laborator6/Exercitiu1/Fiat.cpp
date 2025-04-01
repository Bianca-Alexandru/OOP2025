#include "Fiat.h"
#include <cstring>  

Fiat::Fiat() {
    fuelCapacity = 45;
    fuelConsumption = 6.5;
    avgSpeed[0] = 70;
    avgSpeed[1] = 100;
    avgSpeed[2] = 55;
    strcpy_s(name, sizeof(name), "Fiat");
}

float Fiat::GetSpeed(Weather condition) {
    if (condition == Weather::Rain)
        return avgSpeed[0];
    if (condition == Weather::Sunny)
        return avgSpeed[1];
    if (condition == Weather::Snow)
        return avgSpeed[2];
}

float Fiat::GetFuelCapacity() {
    return fuelCapacity;
}

float Fiat::GetFuelConsumption() {
    return fuelConsumption;
}

const char* Fiat::GetName() {
    return name;
}
