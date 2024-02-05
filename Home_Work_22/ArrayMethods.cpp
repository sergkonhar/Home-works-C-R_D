#include "Array.h"
#include <iostream>
#include <array>
#include <algorithm>

template class DynamicIntArray<int>;


template<class T>
DynamicIntArray<T>::DynamicIntArray()
	:m_dynamicArray(new T[10]), m_dynamicArraySize(0), m_dynamicArrayCapasity(10)
{
}



template<class T>
DynamicIntArray<T>::DynamicIntArray(std::size_t capasity)	
{
	if (capasity <= 0)
	{
		std::cout << "Wrong capasity" << std::endl;
		return;
	}		
	m_dynamicArray = new T[capasity];
	m_dynamicArrayCapasity = capasity;
	m_dynamicArraySize = 0;
}


template<class T>
DynamicIntArray<T>::DynamicIntArray( DynamicIntArray<T>& other)
{
	delete[] m_dynamicArray;
	m_dynamicArray = new T[other.getCapasity()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);

	m_dynamicArraySize = other.m_dynamicArraySize;
	m_dynamicArrayCapasity = other.m_dynamicArrayCapasity;
}

template<class T>
DynamicIntArray<T>::~DynamicIntArray()
{
	delete[] m_dynamicArray;
	m_dynamicArraySize = 0;
	m_dynamicArrayCapasity = 0;
}

template<class T>
DynamicIntArray<T>& DynamicIntArray<T>::operator=(DynamicIntArray<T>& other)
{
	delete[] m_dynamicArray;
	m_dynamicArray = new int[other.getCapasity()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);

	m_dynamicArraySize = other.getSize();
	m_dynamicArrayCapasity = other.getCapasity();
	return *this;
}

template<class T>
T& DynamicIntArray<T>::operator[](std::size_t index)
{
	if (index<0 || index>this->getSize() - 1)
	{
		std::cout << "Wrong index" << std::endl;
		static T defaultElement = 0;
		return defaultElement;
	}

	return m_dynamicArray[index];
}

template<class T>
std::size_t DynamicIntArray<T>::getCapasity()
{
	return m_dynamicArrayCapasity;
}

template<class T>
std::size_t DynamicIntArray<T>::getSize() const
{
	return m_dynamicArraySize;
}

template<class T>
void DynamicIntArray<T>::setSize(std::size_t size)
{
	if (size < this->getSize())
	{
		std::cout << "New size is smaller than original" << std::endl;
		return;
	}

	else if (size < m_dynamicArrayCapasity)
	{
		m_dynamicArraySize = size;
	}

	else
	{
		T* tempArray = new T[this->getCapasity()];

		std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

		delete[] m_dynamicArray;
		m_dynamicArray = new T[size + 10];

		std::copy(tempArray, tempArray + size, m_dynamicArray);

		delete[] tempArray;
		m_dynamicArraySize = size;
		m_dynamicArrayCapasity = size + 10;
	}
}

template<class T>
void DynamicIntArray<T>::clear()
{
	delete[] m_dynamicArray;
	m_dynamicArray = new T[10];
	m_dynamicArraySize = 0;
	m_dynamicArrayCapasity = 10;
}

template<class T>
void DynamicIntArray<T>::push_back(T element)
{
	if (this->getSize() + 1 <= this->getCapasity()) 
	{
		T* tempArray = new T[this->getSize()];
		std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

		delete[] m_dynamicArray;
		m_dynamicArray = new T[(this->getSize() + 1)+10];

		std::copy(tempArray, tempArray + this->getSize(), m_dynamicArray);
		delete[] tempArray;

		m_dynamicArray[this->getSize()] = element;
		m_dynamicArraySize += 1;
		m_dynamicArrayCapasity = (this->getSize() + 1) + 10;
	}

	else 
	{
		m_dynamicArray[this->getSize()] = element;
		m_dynamicArraySize += 1;
	}
}

template<class T>
void DynamicIntArray<T>::reserve(std::size_t reservedSpace) 
{
	if (reservedSpace >= m_dynamicArrayCapasity) 
	{
		std::cout << "New capasity lesser or equal to current capasity" << std::endl;
	}

	else 
	{
		T* tempArray = new T[this->getSize()];
		std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

		delete[] m_dynamicArray;
		m_dynamicArray = new T[reservedSpace];

		std::copy(tempArray, tempArray + this->getSize(), m_dynamicArray);
		delete[] tempArray;

		m_dynamicArrayCapasity = reservedSpace;
	}
}

template<class T>
void DynamicIntArray<T>::shrinkToFit()
{
	T* tempArray = new T[this->getSize()];
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = new T[this->getSize()];

	std::copy(tempArray, tempArray + this->getSize(), m_dynamicArray);
	delete[] tempArray;

	m_dynamicArrayCapasity = this->getSize();
}

template<class T>
void DynamicIntArray<T>::pop_back()
{
	T* tempArray = new T[this->getSize()];
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = new T[this->getCapasity()];

	std::copy(tempArray, tempArray + this->getSize()-2, m_dynamicArray);
	delete[] tempArray;

	m_dynamicArraySize = this->getSize()-2;
}

template<class T>
T DynamicIntArray<T>::back() const
{
	return m_dynamicArray[this->getSize() - 1];
}

template<class T>
bool DynamicIntArray<T>::operator==( DynamicIntArray<T>& other) 
{
	if (this->getSize() != other.getSize() || this->getCapasity() != other.getCapasity()) 
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