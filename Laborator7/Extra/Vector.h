#pragma once

#include <iostream>
using namespace std;

int compare_ints(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

template<typename T>
class Vector {
    T* v;
    int size, capacity;
public:
    Vector() {
        size = 0;
        capacity = 2;
        v = new T[capacity + 1];
    }

    ~Vector() {
        delete v;
    }

    Vector(const Vector& other) {
        capacity = other.capacity;
        size = other.size;
        v = new T[capacity + 1];
        for (int i = 0; i < size; ++i) {
            v[i] = other.v[i];
        }
    }

    T operator[](int index) {
        return v[index];
    }

    void insert(int index, T element) {
        if (index > capacity)
            resize(index);
        v[index] = element;
        size++;
    }

    void remove(int index) {
        for (int i = index;i < size - 1;i++)
            v[i] = v[i + 1];
        size--;
    }

    void sort(int (*cmp)(T, T)) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (compare_ints(v[j], v[j + 1]) > 0) {
                    T temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }

    void print() {
        for (int i = 0;i < size;i++)
            cout << v[i] << " ";
        cout << endl;
    }

    void resize(int size = 0) {
        if (size > capacity * 2)
            capacity = size;
        else capacity *= 2;
        T* v2 = new T[capacity + 1];
        for (int i = 0; i < size; i++) {
            v2[i] = v[i];
        }
        delete[] v;
        v = v2;
    }
};
