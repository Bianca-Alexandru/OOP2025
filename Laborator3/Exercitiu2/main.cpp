#include <iostream>
#include "Canvas.h"
#include <iostream>
using namespace std;

int main() {
    
    Canvas canvas(50, 50);
    
    canvas.DrawCircle(25, 25, 3, 'O');
    
    canvas.FillCircle(15, 20, 6, '*');
    
    canvas.DrawRect(2, 2, 8, 6, '#');
    
    canvas.FillRect(15, 4, 25, 10, '@');
    
    canvas.SetPoint(25, 25, '+');
    
    canvas.DrawLine(1, 1, 50, 50, '-');
    
    cout << "Canvas Output:" << endl;
    canvas.Print();
   
    canvas.Clear();

    cout << "\nCanvas After Clearing:" << endl;
    canvas.Print();

    return 0;
}
