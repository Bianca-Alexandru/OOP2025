#include <iostream>
using namespace std;

float operator"" _Kelvin(long double k) {
    return float(k - 273.15);
}
float operator"" _Fahrenheit(long double f) {
	return float((f - 32) * 5.0 / 9.0);
}
int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
	cout << "300 Kelvin = " << a << " Celsius" << endl;
	cout << "120 Fahrenheit = " << b << " Celsius" << endl;
    return 0;
}
