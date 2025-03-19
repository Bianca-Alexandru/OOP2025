#pragma once
using namespace std;
class Sort
{
    // add data members
    int n, * v;
public:
    // add constuctors
    Sort(int n, int min, int max);
    Sort(int *v);
    Sort(int v[], int n);
    Sort(int x,...);
    Sort(const char s[]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};


