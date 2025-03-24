#include "complex.h"
using namespace std;

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) 
{
    real_data = real;
    imag_data = imag;
    return *this;  
}


Complex operator+(const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r)
{
    return Complex(l.real() + r, l.imag());
}

Complex operator+(double l, const Complex& r)
{
    return Complex(l + r.real(), r.imag());
}

Complex operator-(const Complex& l, const Complex& r)
{
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r)
{
    return Complex(l.real() - r, l.imag());
}

Complex operator-(double l, const Complex& r)
{
    return Complex(l - r.real(), -r.imag());
}

Complex operator*(const Complex& l, const Complex& r)
{
    return Complex(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real());
}

Complex operator*(const Complex& l, double r)
{
    return Complex(l.real() * r, l.imag() * r);
}

Complex operator*(double l, const Complex& r)
{
    return Complex(l * r.real(), l * r.imag());
}


Complex operator-(const Complex& obj)
{
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r)
{
    return l.imag() == r.imag() && l.real() == r.real();
}
bool operator!=(const Complex& l, const Complex& r)
{
    return l.imag() != r.imag() || l.real() != r.real();
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.real())
        out << complex.real() << " ";
    if (complex.imag()) {
        if (complex.imag() < 0) out << "- ";
        else if(complex.real())
            out << "+ ";
        out << abs(complex.imag()) << "i";
    }
    else if (!complex.real())
        out << 0;
    return out;
}

Complex& operator++(Complex& x)  // Prefix
{
    x = Complex(x.real() + 1, x.imag());
    return x;
}

Complex& operator++(Complex& x, int)  // Postfix
{
    Complex temp = x;
    ++x;
    return temp;
}

Complex& operator--(Complex& x)  // Prefix
{
    x = Complex(x.real() - 1, x.imag());
    return x;
}

Complex& operator--(Complex& x, int)  // Postfix
{
    Complex temp = x;
    --x;
    return temp;
}
