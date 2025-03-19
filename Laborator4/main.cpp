#include <iostream>
#include <vector>
#include "Sort.h"

using namespace std;

int main() {

    cout << "Example 1: Creating Sort object using (n, min, max)" << endl;
    Sort sortRandom(10, 1, 100);  
    cout << "Original vector: ";
    sortRandom.Print();

    sortRandom.InsertSort(true);
    cout << "\nSorted in ascending order using InsertSort: ";
    sortRandom.Print();

    sortRandom.InsertSort();
    cout << "\nSorted in descending order using InsertSort: ";
    sortRandom.Print();


    cout << "\n\nExample 2: Creating Sort object using an initialization list" << endl;
    Sort sortArray{ 5, 3, 8, 1, 4, 10, 100, NULL};
    cout << "Original vector: ";
    sortArray.Print();

    sortArray.QuickSort(true);
    cout << "\nSorted in ascending order using QuickSort: ";
    sortArray.Print();

    sortArray.QuickSort();
    cout << "\nSorted in descending order using QuickSort: ";
    sortArray.Print();


    cout << "\n\nExample 3: Creating Sort object using an array and size" << endl;
    int arr2[] = { 10, 20, 5, 7, 3, 13, 2 };
    Sort sortArray2(arr2, 7);  
    cout << "Original vector: ";
    sortArray2.Print();

    sortArray2.BubbleSort(true);
    cout << "\nSorted in ascending order using BubbleSort: ";
    sortArray2.Print();

    sortArray2.BubbleSort();
    cout << "\nSorted in descending order using BubbleSort: ";
    sortArray2.Print();


    cout << "\n\nExample 4: Creating Sort object using variadic arguments" << endl;
    Sort sortVarArgs(5, 9, 3, 6, 2, 4, 10, 15, 5, NULL);  
    cout << "Original vector: ";
    sortVarArgs.Print();

    sortVarArgs.InsertSort(true);
    cout << "\nSorted in ascending order using InsertSort: ";
    sortVarArgs.Print();

    sortVarArgs.QuickSort();
    cout << "\nSorted in descending order using QuickSort: ";
    sortVarArgs.Print();


    cout << "\n\nExample 5: Creating Sort object using a character array" << endl;
    const char* charArray = "10,40,100,5,70";
    Sort sortCharArray(charArray);  
    cout << "Original vector: ";
    sortCharArray.Print();

    sortCharArray.InsertSort(true);
    cout << "\nSorted in ascending order using InsertSort: ";
    sortCharArray.Print();

    sortCharArray.BubbleSort();
    cout << "\nSorted in descending order using BubbleSort: ";
    sortCharArray.Print();


    cout << "\n\nExample 6: Accessing element count and element from index" << endl;
    cout << "Element count in the last sorted vector: " << sortCharArray.GetElementsCount() << endl;
    cout << "Element at index 2: " << sortCharArray.GetElementFromIndex(2) << endl;

    return 0;
}
