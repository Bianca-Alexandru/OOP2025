#include <iostream>
using namespace std;

template<typename K, typename V>
class Map {
    struct Entry {
        K key;
        V value;
    };

    Entry* elements;
    int size;
    int capacity;

    void Resize() {
        capacity *= 2;
        Entry* newElements = new Entry[capacity];
        for (int i = 0; i < size; ++i)
            newElements[i] = elements[i];
        delete[] elements;
        elements = newElements;
    }

    int FindIndex(const K& key) const {
        for (int i = 0; i < size; ++i)
            if (elements[i].key == key)
                return i;
        return -1;
    }

public:
    Map() {
        capacity = 10;
        size = 0;
        elements = new Entry[capacity];
    }

    ~Map() {
        delete[] elements;
    }

    V& operator[](const K& key) {
        int index = FindIndex(key);
        if (index != -1) {
            return elements[index].value;
        }

        if (size == capacity)
            Resize();

        elements[size].key = key;
        return elements[size++].value;
    }

    void Set(const K& key, const V& value) {
        int index = FindIndex(key);
        if (index != -1) {
            elements[index].value = value;
        }
        else {
            if (size == capacity)
                Resize();
            elements[size++] = { key, value };
        }
    }

    bool Get(const K& key, V& value) const {
        int index = FindIndex(key);
        if (index != -1) {
            value = elements[index].value;
            return true;
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Delete(const K& key) {
        int index = FindIndex(key);
        if (index == -1)
            return false;
        for (int i = index; i < size - 1; ++i)
            elements[i] = elements[i + 1];
        --size;
        return true;
    }

    bool Includes(const Map<K, V>& other) const {
        for (int i = 0; i < other.size; ++i) {
            if (FindIndex(other.elements[i].key) == -1)
                return false;
        }
        return true;
    }

    struct EntryWithIndex {
        K key;
        V value;
        int index;
    };

    struct Iterator {
        Map& map;
        int index;

        Iterator(Map& map, int index) : map(map), index(index) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
        }

        EntryWithIndex operator*() const {
            return EntryWithIndex{ map.elements[index].key, map.elements[index].value, index };
        }
    };

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, size);
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
