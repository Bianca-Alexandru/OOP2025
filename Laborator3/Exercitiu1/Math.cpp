#include "Math.h"
#include <cstdarg>  // for va_list, va_start, va_arg, va_end
#include <cstring>  // for strcat
/*class Math
{
public:
    static int Add(int,int);
    static int Add(int,int,int);
    static int Add(double,double);
    static int Add(double,double,double);
    static int Mul(int,int);
    static int Mul(int,int,int);
    static int Mul(double,double);
    static int Mul(double,double,double);
    static int Add(int count,...); // sums up a list of integers
    static char* Add(const char *, const char *);
};
*/

int Math::Add(int x, int y) {
    return x + y;
}
int Math::Add(int x, int y, int z) {
    return x + y + z;
}
int Math::Add(double x, double y) {
    return x + y;
}
int Math::Add(double x, double y, double z) {
    return x + y + z;
}
int Math::Mul(int x, int y) {
    return x * y;
}
int Math::Mul(int x, int y, int z) {
    return x * y * z;
}
int Math::Mul(double x, double y) {
    return x * y;
}
int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    va_list args;      
    va_start(args, count); 

    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);  
    }

    va_end(args);  
    return sum;
}
char* Math::Add(const char* x, const char* y) {
    if (!x || !y)
        return nullptr;
    int len1 = strlen(x);
    int len2 = strlen(y);

    char* result = new char[len1 + len2 + 1]; // Allocate memory
    result[0] = '\0';
    strcat_s(result, len1 + len2 + 1, x);
    strcat_s(result, len1 + len2 + 1, y);

    return result;
}





