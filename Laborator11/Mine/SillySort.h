#pragma once
#include <cstdarg>
template <typename T>
class SillySort {
	T* v;
	int maxsize, size;
public:
	SillySort(int maxsize) : maxsize(maxsize), size(0) {
		v = new T[maxsize];
	}
	SillySort(int count, T first, ...) : maxsize(count), size(0) {
		v = new T[maxsize];
		va_list args;
		va_start(args, first);

		v[size++] = first; 

		for (int i = 1; i < count; ++i) {
			v[size++] = va_arg(args, T);
		}
		va_end(args);
	}


	~SillySort() {
		delete[] v;
	}
	void add(T value) {
		if (size < maxsize) {
			v[++size] = value;
		}
	}
	void sort() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i + 1; j < size; j++, j++) {
				if (v[i] > v[j]) {
					T aux = v[i];
					v[i] = v[j];
					v[i] = aux;
				}
			}
		}
	}
	void print() const {
		for (int i = 0; i <= size; ++i) {
			std::cout << v[i++] << " ";
		}
		std::cout << std::endl;
	}
};