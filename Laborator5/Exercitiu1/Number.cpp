#include "Number.h"
#include <iostream>
using namespace std;

Number::Number(const char* value, int base) {
    this->base = base;
    this->length = 0;
    int i = 0;
    while (value[i] != '\0') {
        this->length++;
        i++;
    }

    v = new int[length];  

    i = 0;
    while (value[i] != '\0') {
        if (value[i] >= '0' && value[i] <= '9')
            v[i] = int(value[i] - '0');
        else
            v[i] = int(value[i] - 'A' + 10);
        i++;
    }
}

// Copy Constructor
Number::Number(const Number& n) {
    base = n.base;
    length = n.length;
    v = new int[length];  

    for (int i = 0; i < length; i++) {
        v[i] = n.v[i];  
    }
}

// Move Constructor
Number::Number(Number&& n) {
    base = n.base;
    length = n.length;
    v = n.v;  

    n.v = nullptr;  
    n.length = 0;   
    n.base = 0;     
}

Number::Number(int n) {
    base = 10;
    length = 0;
    int temp = n;
    while (temp > 0) {
        length++;
        temp /= base;
    }

    v = new int[length];
    for (int i = 0; i < length; i++) {
        v[length - i - 1] = n % base;
        n /= base;
    }
}

Number::~Number() {
    delete[] v;
}

// Convert the current Number object to base 10
int Number::ToDecimal() const {
    int decimalValue = 0;
    int power = 1;

    for (int i = length - 1; i >= 0; i--) {
        decimalValue += v[i] * power;
        power *= base;
    }

    return decimalValue;
}

Number operator+(const Number& n1, const Number& n2) {
    int resultBase = (n1.base > n2.base) ? n1.base : n2.base;

    int n1Decimal = n1.ToDecimal();
    int n2Decimal = n2.ToDecimal();

    int resultDecimal = n1Decimal + n2Decimal;

    Number result(resultDecimal);  
    result.SwitchBase(resultBase);  
    return result;
}

Number operator-(const Number& n1, const Number& n2) {
    int resultBase = (n1.base > n2.base) ? n1.base : n2.base;

    int n1Decimal = n1.ToDecimal();
    int n2Decimal = n2.ToDecimal();

    int resultDecimal = n1Decimal - n2Decimal;

    Number result(resultDecimal);  
    result.SwitchBase(resultBase);  
    return result;
}


bool Number::operator > (const Number& n) {
    Number temp1 = *this;
    Number temp2 = n;

    temp1.SwitchBase(10);
    temp2.SwitchBase(10);

    return temp1.ToDecimal() > temp2.ToDecimal();
}


bool Number::operator < (const Number& n) {
    Number temp1 = *this;
    Number temp2 = n;

    temp1.SwitchBase(10);
    temp2.SwitchBase(10);

    return temp1.GetDigitsCount() < temp2.GetDigitsCount();
}

bool Number::operator >= (const Number& n) {
    return !(*this < n);
}

bool Number::operator <= (const Number& n) {
    return !(*this > n);
}

bool Number::operator == (const Number& n) {
    Number temp1 = *this;
    Number temp2 = n;

    temp1.SwitchBase(10);
    temp2.SwitchBase(10);

    return temp1.GetDigitsCount() == temp2.GetDigitsCount();
}

char Number::operator[](int index) {
    if (index >= 0 && index < length) {
        if (v[index] < 10)
            return char(v[index] + '0');
        else
            return char(v[index] + 'A' - 10);
    }
    else {
        cout << "Out of range" << endl;
        return -1; 
    }
}


Number& Number::operator=(const Number& n) {
    if (this != &n) {  
        delete[] v; 
        length = n.length;
        base = n.base;
        v = new int[length];  
        for (int i = 0; i < length; i++) {
            v[i] = n.v[i];  
        }
    }
    return *this;
}

Number& Number::operator=(int val) {
    length = 0;
    int temp = val;
    while (temp > 0) {
        length++;
        temp /= base;
    }

    v = new int[length];
    for (int i = 0; i < length; i++) {
        v[length - i - 1] = val % base;
        val /= base;
    }

    return *this;
}

Number& Number::operator=(const char* c) {
    delete[] v;
    length = strlen(c);
    v = new int[length];
    for (int i = 0; i < length; i++) {
        char ch = c[i];
        if (ch >= '0' && ch <= '9') {
            v[i] = ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F') {
            v[i] = ch - 'A' + 10;
        }
        else if (ch >= 'a' && ch <= 'f') {
            v[i] = ch - 'a' + 10;
        }
        else {
            throw std::invalid_argument("Invalid character in value.");
        }
    }
    return *this;
}

Number& Number::operator+=(const Number& n) {
    *this = *this + n;
    return (*this);
}

void Number::operator--() {
    if (length > 0) {
        for (int i = 0; i < length - 1; i++)
            v[i] = v[i + 1];
        length--;
    }
}

void Number::operator--(int) {
    if (length > 0)
        length--;
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16) {
        cout << "Invalid base!" << endl;
        return;
    }

    int decimalValue = 0;
    int power = 1;

    for (int i = length - 1; i >= 0; i--) {
        decimalValue += v[i] * power;
        power *= base;
    }

    int newLength = 0;
    int tempValue = decimalValue;
    while (tempValue > 0) {
        tempValue /= newBase;
        newLength++;
    }

    int* newDigits = new int[newLength];

    for (int i = 0; i < newLength; i++) {
        newDigits[i] = decimalValue % newBase;
        decimalValue /= newBase;
    }

    base = newBase;
    length = newLength;

    v = new int[length];

    for (int i = 0; i < length; i++) {
        v[i] = newDigits[length - 1 - i];
    }

    delete[] newDigits;  
}



void Number::Print() {
    for (int i = 0; i < length; i++)
        cout << (char)(v[i] < 10 ? v[i] + '0' : v[i] + 'A' - 10);
    cout << endl;
}

int Number::GetDigitsCount() {
    return this->length;
}

int Number::GetBase() {
    return this->base;
}
