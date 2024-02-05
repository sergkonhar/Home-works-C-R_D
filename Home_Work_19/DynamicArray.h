#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
   
    DynamicIntArray();

   
    DynamicIntArray(std::size_t size);

   
    DynamicIntArray(const DynamicIntArray& other);

    
    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);

    int& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(int element);

private:

    int* m_dynamicArray = nullptr;
    int m_dynamicArraySize;
};