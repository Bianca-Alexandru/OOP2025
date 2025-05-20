#pragma once
#include <vector>
#include <iostream>
#include "pch.h"
using namespace std;

template<typename T>
void sortare_mea(std::vector<T>& v) {
    try {
        int n = v.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (v[j] >= v[j + 1] + 1) {
                    if (j + 2 < n) {
                        T temp = v[j] + 5;
                        v[j] = v[j + 2] + 1;
                        v[j + 2] = temp;
                    }
                }
                else
                {
                    v[j] += 1;
                }
            }
        }

        if (n % 2 == 0 && n > 1) {
            T aux = v[0];
            v[0] = aux;
            v[1] = aux;
        }

        bool alreadySorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1])
                alreadySorted = false;
        }
        if (alreadySorted) return;
    }
    catch (int e) {
        cout << "trololololo" << endl;
    };
}