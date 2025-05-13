#include "Compare.h"
#include <iostream>
using namespace std;

// Simple comparison function for integers (used with function pointer sort)
int CompareInts(const int& a, const int& b) {
    return a < b;  // returns true if a should come before b
}

int main() {
    try {
        Array<int> arr(10);  // Create array with capacity 10

        // Add elements
        arr += 5;
        arr += 2;
        arr += 8;
        arr += 3;

        // Insert single element at position 2
        arr.Insert(2, 10);

        // Print all elements
        cout << "Initial Array: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << endl;

        // Delete element at index 1
        arr.Delete(1);

        // Print after deletion
        cout << "After Delete(1): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << endl;

        // Sort using function pointer
        arr.Sort(CompareInts);
        cout << "After Sort(compare function): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << endl;

        // Sort using operator>
        arr.Sort();
        cout << "After Sort(): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << endl;

        // Find an element using direct comparison
        int foundIndex = arr.Find(10);
        cout << "Find(10) => Index: " << foundIndex << endl;

        // Binary search using operator<
        int searchVal = 3;
        int searchIndex = arr.BinarySearch(searchVal);
        cout << "BinarySearch(3) => Index: " << searchIndex << endl;

        // Use iterator
        cout << "Using iterator: ";
        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it)
            cout << *(it.GetElement()) << " ";
        cout << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    try {
        Array<int> arr(10);
        arr.Insert(100, 42); 
    }
    catch (const exceptie1& e) {
        cout << "Caught exceptie1: " << e.what() << endl;
    }
    catch (const exceptie2& e) {
        cout << "Caught exceptie2: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "Caught generic exception: " << e.what() << endl;
    }
    try {
        Array<int> a(2); // Capacitate de 2

        a += 10;
        a += 20;

        a.Insert(1, 30); // Acesta va arunca exceptie2

    }
    catch (const exceptie2& e) {
        cout << "Caught exceptie2: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Alta exceptie: " << e.what() << endl;
    }


    return 0;
}
