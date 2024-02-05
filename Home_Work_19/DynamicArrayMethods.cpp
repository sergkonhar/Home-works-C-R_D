#include "DynamicArray.h"
#include <iostream>
#include <array>
#include <algorithm>

DynamicIntArray::DynamicIntArray() 
	:m_dynamicArray(new int[0]), m_dynamicArraySize(0)
{
}

DynamicIntArray::DynamicIntArray(std::size_t size) 
{
	m_dynamicArray = new int[size];
	m_dynamicArraySize = size;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) 
{
	delete[] m_dynamicArray;
	m_dynamicArray = new int[other.getSize()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);
		
	m_dynamicArraySize = other.m_dynamicArraySize;
}


DynamicIntArray::~DynamicIntArray() 
{
	delete[] m_dynamicArray;
	m_dynamicArraySize = 0;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	delete[] m_dynamicArray;
	m_dynamicArray = new int[other.getSize()];

	std::copy(other.m_dynamicArray, other.m_dynamicArray + other.getSize(), m_dynamicArray);

	m_dynamicArraySize = other.getSize();
	return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
	if (index<0 || index>this->getSize() - 1) 
	{
		std::cout << "Wrong index" << std::endl;
		int errorValue = 0;
		return errorValue;
	}

	return m_dynamicArray[index];
}

std::size_t DynamicIntArray::getSize() const 
{
	return m_dynamicArraySize;
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	if (newSize< this->getSize())
	{
		std::cout << "New size is smaller than original" << std::endl;
		return ;
	}

	int* tempArray = new int[this->getSize()];
	
	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = new int[newSize];

	std::copy(tempArray, tempArray+newSize, m_dynamicArray);

	delete[] tempArray;
	m_dynamicArraySize = newSize;
}

void DynamicIntArray::clear()
{
	delete[] m_dynamicArray;
	m_dynamicArray = new int[0];
}

void DynamicIntArray::push_back(int element) 
{
	int* tempArray = new int[this->getSize()];

	std::copy(m_dynamicArray, m_dynamicArray + this->getSize(), tempArray);

	delete[] m_dynamicArray;
	m_dynamicArray = new int[this->getSize()+1];


	std::copy(tempArray, tempArray + this->getSize(), m_dynamicArray);

	delete[] tempArray;
	m_dynamicArray[this->getSize()] = element;

	m_dynamicArraySize += 1;
}