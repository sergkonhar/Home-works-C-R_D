#pragma once
#include <cstdlib>

template<class T>
class DynamicIntArray
{
public:

    DynamicIntArray();


    DynamicIntArray(std::size_t capasity);


    DynamicIntArray( DynamicIntArray& other);


    ~DynamicIntArray();

    DynamicIntArray& operator=( DynamicIntArray& other);

    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(T element);

    std::size_t getCapasity();

    void reserve(std::size_t reservedSpace);

    void shrinkToFit();

    void pop_back();

    T back() const;

    bool operator==( DynamicIntArray& other);

private:

    T* m_dynamicArray = nullptr;
    int m_dynamicArraySize;
    int m_dynamicArrayCapasity;
};