#include "Canvas.h"
#include <cmath>
#include <iostream>
using namespace std;

/*Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas*/

Canvas::Canvas(int width, int height) {
    a = new char* [height]; 
    for (int i = 0; i < height; i++) 
        a[i] = new char[width];
    this->width = width;
    this->height = height;
    
    Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    float cx, cy;
    for (int i = 0;i < 360;i+=3) {
        cx = x + cos(i) * ray;
        cy = y + sin(i) * ray;
        int aa, b;
        aa = round(cx);
        b = round(cy);
        a[aa][b] = ch;
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    float cx, cy;
    for (int i = 0;i < 360;i+=3) 
        for(int j=0;j<=ray;j++){
        cx = x + cos(i) * j;
        cy = y + sin(i) * j;
        int aa, b;
        aa = round(cx);
        b = round(cy);
        a[aa][b] = ch;
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left;i <= right;i++)
        a[i][top] = a[i][bottom] = ch;
    for (int i = top;i <= bottom;i++)
        a[left][i] = a[right][i] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left;i <= right;i++)
        for(int j=top;j<=bottom;j++)
        a[i][j]  = ch;
}
void Canvas::SetPoint(int x, int y, char ch) {
    a[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    /*dx = x1 - x0
    dy = y1 - y0
    D = 2*dy - dx
    y = y0

    for x from x0 to x1
        plot(x, y)
        if D > 0
            y = y + 1
            D = D - 2*dx
        end if
        D = D + 2*dy*/
    int dx, dy, D, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    D = 2 * dy - dx;
    y = y1;
    for (x = x1;x <= x2;x++) {
        if (x >= 0 && x < width && y >= 0 && y < height)
            a[x][y] = ch;
        if (D > 0) {
            y++;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
    }
}
void Canvas::Print() {
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++)
            cout << a[i][j];
        cout << endl;
    }
}
void Canvas::Clear() {
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++)
            a[i][j] = ' ';
    }
}
