#include <iostream>
#include "SillySort.h"
int main() {
	SillySort<int> s1(10);
	s1.add(5);
	s1.add(2);
	s1.add(8);
	s1.add(1);
	s1.add(10);
	s1.add(3);
	s1.print(); 
	s1.sort();
	s1.print(); 

	std::cout << "-----------\n";

	SillySort<int> s2(5, 10, 3, 7, 2, 9, 1, 2, 6, 4);
	s2.print();
	s2.sort();
	s2.print();

	return 0;
}
