#include <iostream>
#include <exception>
using namespace std;
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template <class T>
class Array;

class exceptie1 : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Index out of range";
    }
};
class exceptie2 : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Array is full";
    }
};

template<class T>
class ArrayIterator
{
    friend class Array<T>;
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    Array<T>* array;
    int size;
public:
    ArrayIterator() {
        Current = 0;
        array = nullptr;
        size = 0;
    };
    ArrayIterator& operator ++ () {
        Current++;
        return *this;
    };
    ArrayIterator& operator -- () {
        Current--;
        return *this;
    };
    bool operator= (ArrayIterator<T>&) {
        return Current == size;
    };
    bool operator!=(ArrayIterator<T>&) {
        return Current != size;
    };
    bool operator!=(const ArrayIterator<T>& other) {
        return Current != other.Current;
    }


    T* GetElement() {
        return array->List[Current];
    };
};


template<class T>
class Array
{
	friend class ArrayIterator<T>; 
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }; // Lista nu e alocata, Capacity si Size = 0
    ~Array() {
        delete[] List;
    }; // destructor
    Array(int capacity) {
        Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
    }; // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
    }; // constructor de copiere

    T& operator[] (int index) {
        if (index < 0 || index >= Size) {
            throw exceptie1();
        }
        return *List[index];
    }; // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem) {
        if (Size < Capacity) {
            List[Size] = new T(newElem);
            Size++;
        }
        return *this;
    }; // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw exceptie1();
        }
        if (Size == Capacity) {
            throw exceptie2();
        }
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }; // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) {
            throw exceptie1();
        }
        if (Size + otherArray.Size > Capacity) {
            throw exceptie2();
        }
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }; // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw exceptie1();
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }; // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) {
            return *this;
        }
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
        return *this;
    }


    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }; // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]))
                    swap(List[i], List[j]);
    }; // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]))
                    swap(List[i], List[j]);
    }; // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(T& elem) {
        int low = 0;
        int high = Size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }; // cauta un element folosind binary search in Array
    int BinarySearch(T& elem, int(*compare)(const T&, const T&)) {
        int low = 0;
        int high = Size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmpResult = compare(*List[mid], elem);
            if (cmpResult == 0)
                return mid;
            if (cmpResult < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    };//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(T& elem, Compare* comparator) {
        int low = 0;
        int high = Size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmpResult = comparator->CompareElements(static_cast<void*>(List[mid]), static_cast<void*>(&elem));
            if (cmpResult == 0)
                return mid;
            if (cmpResult < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    };//  cauta un element folosind binary search si un comparator

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }; // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    };//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(*List[i], elem) == 0)
                return i;
        return -1;
    };//  cauta un element folosind un comparator

    int GetSize() {
        return Size;
    };
    int GetCapacity() {
        return Capacity;
    };

    ArrayIterator<T> GetBeginIterator() {
        ArrayIterator<T> it;
        it.Current = 0;
        it.array = this;
        it.size = Size;
        return it;
    };
    ArrayIterator<T> GetEndIterator() {
        ArrayIterator<T> it;
        it.Current = Size;
        it.array = this;
        it.size = Size;
        return it;
    };
};
