#include "Array.h"
#include <iostream>
#include <array>
#include <algorithm>
#define MY_ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << #condition << ", " << message << " in file " << __FILE__ \
                  << " at line " << __LINE__ << std::endl; \
        std::terminate(); \
    }

template class DynamicArray<int>;

const int baseCapasity = 10;


template<class T>
DynamicArray<T>::DynamicArray()
	:m_dynamicArray(new T[baseCapasity]), m_dynamicArraySize(0), m_dynamicArrayCapacity(baseCapasity)
{
}



template<class T>
DynamicArray<T>::DynamicArray(int capacity)	
{
	if (capacity <= 0)
	{
		std::cout << "Wrong capacity" << std::endl;
		return;
	}		
	m_dynamicArray = new T[capacity];
	m_dynamicArrayCapacity = capacity;
	m_dynamicArraySize = 0;
}


template<class T>
DynamicArray<T>::DynamicArray( DynamicArray<T>& other)
{
	m_dynamicArray = new T[other.getCapacity()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);

	m_dynamicArraySize = other.m_dynamicArraySize;
	m_dynamicArrayCapacity = other.m_dynamicArrayCapacity;
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] m_dynamicArray;
	m_dynamicArraySize = 0;
	m_dynamicArrayCapacity = 0;
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>& other)
{
	delete[] m_dynamicArray;
	m_dynamicArray = new int[other.getCapacity()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);

	m_dynamicArraySize = other.getSize();
	m_dynamicArrayCapacity = other.getCapacity();
	return *this;
}

template<class T>
T& DynamicArray<T>::operator[](int index)
{		
	MY_ASSERT(index>0 || index<this->getSize() - 1, "Wrong index")
			
	return m_dynamicArray[index];
}

template<class T>
int DynamicArray<T>::getCapacity()
{
	return m_dynamicArrayCapacity;
}

template<class T>
int DynamicArray<T>::getSize() const
{
	return m_dynamicArraySize;
}

template<class T>
void DynamicArray<T>::setSize(int size)
{
	MY_ASSERT(size>=0, "Wrong size")

	m_dynamicArraySize = size;
}

template<class T>
void DynamicArray<T>::clear()
{
	delete[] m_dynamicArray;
	m_dynamicArray = new T[baseCapasity];
	m_dynamicArraySize = 0;
	m_dynamicArrayCapacity = baseCapasity;
}

template<class T>
void DynamicArray<T>::push_back(T element)
{
	if (this->getSize() + 1 <= this->getCapacity()) 
	{
		T* tempArray = new T[(this->getSize() + 1) + baseCapasity];
		std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

		delete[] m_dynamicArray;
		m_dynamicArray = tempArray;

		m_dynamicArray[this->getSize()] = element;
		m_dynamicArraySize += 1;
		m_dynamicArrayCapacity = (this->getSize() + 1) + baseCapasity;

	}

	else 
	{
		m_dynamicArray[this->getSize()] = element;
		m_dynamicArraySize += 1;
	}
}

template<class T>
void DynamicArray<T>::reserve(int reservedSpace) 
{

	MY_ASSERT(reservedSpace >= m_dynamicArrayCapacity, "New reserve lesser than current")

		T* tempArray = new T[reservedSpace];
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = tempArray;

	m_dynamicArrayCapacity = reservedSpace;
	
}

template<class T>
void DynamicArray<T>::shrinkToFit()
{
	T* tempArray = new T[this->getSize()];
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = tempArray;

	m_dynamicArrayCapacity = this->getSize();
}

template<class T>
void DynamicArray<T>::pop_back()
{
	T* tempArray = new T[this->getCapacity()];
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize()-2, tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = tempArray;

	m_dynamicArraySize = this->getSize() - 1;
}

template<class T>
T DynamicArray<T>::back() const
{
	MY_ASSERT(this->getSize() > 0, "Size is 0")
	return m_dynamicArray[this->getSize() - 1];
}

template<class T>
bool DynamicArray<T>::operator==( DynamicArray<T>& other) 
{
	if (this->getSize() != other.getSize() || this->getCapacity() != other.getCapacity()) 
	{
		return false;
	}
	
	for (int i = 0; i < other.getSize(); i++) 
	{
		if (m_dynamicArray[i] != other.m_dynamicArray[i]) 
		{
			return false;
		}
	}
	return true;
}