#include "Canvas.h"
#include <cstdarg>
#include <iostream>
using namespace std;
/*// contructor will call the clear method
    Canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;*/
Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
    a = new char* [lines];
    a = new char* [lines];
    for (int i = 0; i < lines; i++) 
        a[i] = new char[columns]; 

    clear();
}
void Canvas::set_pixel(int x, int y, char value) {
    a[x][y] = value;
}
void Canvas::set_pixels(int count, ...) {
    
    va_list args;
    va_start(args, count);
    for (int i = 0;i < count;i += 2) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        if (x >= 0 && x < lines && y >= 0 && y < columns)
             set_pixel(x, y, 'x');
    }
    va_end(args);
}
void Canvas::print() const{
    for (int i = 0;i < lines;i++) {
        for (int j = 0;j < columns;j++)
            cout << a[i][j];
        cout << endl;
    }
}
void Canvas::clear() {
    for (int i = 0;i < lines;i++) {
        for (int j = 0;j < columns;j++)
            a[i][j] = ' ';
    }
}