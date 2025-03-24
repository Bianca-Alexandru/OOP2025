#include "Number.h"
#include <iostream>

int main() {
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    std::cout << "n1 has " << n1.GetDigitsCount() << " digits and it is written in base " << n1.GetBase() << std::endl;

    for (int tr = 0; tr < n1.GetDigitsCount(); tr++) {
        std::cout << "n1[" << tr << "] = " << (char)(n1[tr]) << std::endl;
    }

    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1; // example
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) std::cout << "n1 is bigger than n2" << std::endl;
    else std::cout << "n2 is bigger than n1" << std::endl;

    Number n4 = 12345; // n4 will be in base 10
    n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
    n1.Print();
    n4 += n1;
    n4.Print();

    n4 = "13579"; // maintains its base (10)
    n4.Print();
    --n4; // remove the first digit from n4 ==> n4 becomes 3579
    n4.Print();
    n4--; // remove the last digit ==> n4 becomes 357
    n4.Print();

    return 0;
}
