#include <iostream>
#include "Math.h"

using namespace std;

int main() {
    // Testing Add functions
    cout << "Add(2, 3) = " << Math::Add(2, 3) << endl;
    cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << endl;
    cout << "Add(2.5, 3.5) = " << Math::Add(2.5, 3.5) << endl;
    cout << "Add(1.1, 2.2, 3.3) = " << Math::Add(1.1, 2.2, 3.3) << endl;

    // Testing Mul functions
    cout << "Mul(2, 3) = " << Math::Mul(2, 3) << endl;
    cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << endl;
    cout << "Mul(2.5, 3.5) = " << Math::Mul(2.5, 3.5) << endl;
    cout << "Mul(1.1, 2.2, 3.3) = " << Math::Mul(1.1, 2.2, 3.3) << endl;

    // Testing variadic Add function
    cout << "Add(5, 1, 2, 3, 4, 5) = " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    // Testing Add function for string concatenation
    char* result = Math::Add("Hello, ", "World!");
    if (result) {
        cout << "Add(\"Hello, \", \"World!\") = " << result << endl;
        delete[] result; // Free allocated memory
    }

    return 0;
}
