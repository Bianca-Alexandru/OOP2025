#include "NumberList.h"
#include <iostream>
using namespace std;

int main() {
    NumberList list;
    list.Init();

    list.Add(5);
    list.Add(2);
    list.Add(9);
    list.Add(1);
    list.Add(7);

    cout << "Before sorting: ";
    list.Print();

    list.Sort();

    cout << "After sorting: ";
    list.Print();

    return 0;
}
