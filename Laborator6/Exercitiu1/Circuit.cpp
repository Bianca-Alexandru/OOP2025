#include "Circuit.h"
#include <iostream>
using namespace std;
void Circuit::SetLength(float n)
{
	this->length = n;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car) {
	v[n++] = car;
}

void Circuit::Race()
{
	for (int i = 0;i < n;i++) {
		float spd, FuelNeeded;
		spd = v[i]->GetSpeed(weather);
		FuelNeeded = length * v[i]->GetFuelConsumption()/15;
		if (FuelNeeded > v[i]->GetFuelCapacity())
			time[i] = -1;
		else time[i] = length / (spd/3.6);//km/h ->m/s
	}
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++) 
			if (time[i] > time[j]) {
				swap(time[i], time[j]);
				swap(v[i], v[j]);
			}
	for (int i = 0;i < n;i++)
		if (time[i] != -1)
			cout << v[i]->GetName() << " " << time[i] << endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0;i < n;i++)
		if (time[i] == -1)
			cout << v[i]->GetName() << " did not finish" << endl;
}
