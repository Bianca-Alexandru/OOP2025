#include "Sort.h"
#include <ctime>
#include <cstdlib>
#include <stdarg.h>
#include <cstring>
#include <iostream>
using namespace std;
/*  Sort(int n, int min, int max);
    Sort(int *v);
    Sort(int v[], int n);
    Sort(...);
    Sort(char s[]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);*/
Sort::Sort(int n, int min, int max) {
    this->n = n;
    v = new int [n];
    srand(time(0));
    for (int i = 0;i < n;i++) {
        v[i]= min + rand() % (max - min + 1);
    }
}
Sort::Sort(int* v) {
    this->n = 0;
    this->v = v;
    int* temp = v;

    while (temp != nullptr && *temp != NULL) {
        n++;
        temp++;
    }
    cout << 1;
}
Sort::Sort(int a[], int n) {
    this->n = n;
    v = new int[n];
    for (int i = 0;i < n;i++)
        this->v[i] = a[i];
}
Sort::Sort(int x,...) {
    this->n = 1;
    va_list args;
    va_start(args, x);
    int i = 1;
    int arg;
    while ((arg=va_arg(args,int)) != NULL) {
        this->n++;
    }
    v = new int[n];
    v[0] = x;
    va_end(args);
    va_start(args, x);
    while ((arg = va_arg(args, int)) != NULL) {
        v[i++] = arg;
    }
    va_end(args);
}
Sort::Sort(const char s[]) {
    this->n = 1;
    for (int i = 0;i < strlen(s);i++)
        if (s[i] == ',')this->n++;
    v = new int[n];
    int i2 = 0, x=0;
    for (int i = 0;i < strlen(s);i++) {
        if (s[i] == ',') {
            v[i2++] = x;
            x = 0;
        }
        else {
            x = x * 10 + s[i] - '0';
        }
    }
    v[i2] = x;
}
void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;
        if (ascendent) {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                --j;
            }
        }
        else {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                --j;
            }
        }
        v[j + 1] = key;
    }
}


int Partition(int low, int high, bool ascendent, int v[]) {
    int pivot = v[high]; 
    int i = low - 1;     

    for (int j = low; j < high; ++j) {
        if (ascendent) {
            if (v[j] < pivot) { 
                i++;
                swap(v[i], v[j]);
            }
        }
        else {
            if (v[j] > pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }
    }
    swap(v[i + 1], v[high]); 
    return i + 1;
}
void QuickSortHelper(int low, int high, bool ascendent, int v[]) {
    if (low < high) {
        int pivotIndex = Partition(low, high, ascendent, v);
        QuickSortHelper(low, pivotIndex - 1, ascendent, v);
        QuickSortHelper(pivotIndex + 1, high, ascendent, v);
    }
}
void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, n - 1, ascendent, v);
}


void Sort::BubbleSort(bool ascendent) {
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (ascendent) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    swapped = true;
                }
            }
            else {
                if (v[j] < v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    swapped = true;
                }
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void Sort::Print() {
    for (int i = 0;i < n;i++)
        cout << v[i] << " ";
}
int Sort::GetElementsCount() {
    return this->n;
}
int Sort::GetElementFromIndex(int index) {
    return v[index];
}