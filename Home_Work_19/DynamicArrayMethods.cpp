#include "DynamicArray.h"
#include <iostream>
#include <array>

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

	for (int i = 0; i < other.getSize(); i++)
	{
		m_dynamicArray[i] = other.m_dynamicArray[i];
	}

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

	for (int i = 0; i < other.getSize(); i++)
	{
		m_dynamicArray[i] = other.m_dynamicArray[i];
	}

	m_dynamicArraySize = other.getSize();
	return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
	return m_dynamicArray[index];
}

std::size_t DynamicIntArray::getSize() const 
{
	return m_dynamicArraySize;
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	int* tempArray = new int[this->getSize()];

	for (int i = 0; i < this->getSize(); i++)
	{
		tempArray[i] = m_dynamicArray[i];
	}

	delete[] m_dynamicArray;
	m_dynamicArray = new int[newSize];

	int tempArraySize = sizeof(*tempArray) / sizeof(int);

	for (int i = 0; i < this->getSize(); i++)
	{
		m_dynamicArray[i] = tempArray[i];
	}

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

	for (int i = 0; i < this->getSize(); i++)
	{
		tempArray[i] = m_dynamicArray[i];
	}

	delete[] m_dynamicArray;
	m_dynamicArray = new int[this->getSize()+1];


	for (int i = 0; i < this->getSize(); i++)
	{
		m_dynamicArray[i] = tempArray[i];
	}

	delete[] tempArray;
	m_dynamicArray[this->getSize()] = element;

	m_dynamicArraySize += 1;
}