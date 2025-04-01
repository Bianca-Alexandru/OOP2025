#pragma once
#include "Car.h"
#include "Weather.h"
#include <iostream>
class Circuit
{
	float length;
	Weather weather;
	int n = 0;
	Car *v[50];
	float time[50];
public:
	void SetLength(float n);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

