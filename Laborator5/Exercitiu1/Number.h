#pragma once

class Number
{
    int base, * v, length;
public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int n); // constructor for an integer (base 10)
    Number(const Number& n);
    Number(Number&& n);
    ~Number();

    bool operator > (const Number& n);
    bool operator < (const Number& n);
    bool operator >= (const Number& n);
    bool operator <= (const Number& n);
    bool operator == (const Number& n);
    char operator [] (int index);  

    Number& operator = (const Number& n);
    Number& operator = (int val);
    Number& operator = (const char* c);
    Number& operator += (const Number& n);

    void operator--(); // prefix -- operator
    void operator--(int); // postfix -- operator

    int ToDecimal() const;
    friend Number operator + (const Number& n1, const Number& n2);
    friend Number operator - (const Number& n1, const Number& n2);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase(); 
};
