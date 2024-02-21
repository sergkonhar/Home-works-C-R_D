#pragma once
#include <cstdlib>

template<class T>
class DynamicArray
{
public:

    DynamicArray();


    DynamicArray(int capacity);


    DynamicArray( DynamicArray& other);


    ~DynamicArray();

    DynamicArray& operator=( DynamicArray& other);

    T& operator[](int index);

    void setSize(int newSize);
    int getSize() const;

    void clear();

    void push_back(T element);

    int getCapacity();

    void reserve(int reservedSpace);

    void shrinkToFit();

    void pop_back();

    T back() const;

    bool operator==( DynamicArray& other);

private:

    T* m_dynamicArray = nullptr;
    int m_dynamicArraySize;
    int m_dynamicArrayCapacity;
};