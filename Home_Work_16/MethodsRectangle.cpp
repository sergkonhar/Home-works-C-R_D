#include "ClassRectangle.h"


Rectangle::Rectangle() 
{
	m_sideA = 10;
	m_sideB = 10;
}

Rectangle::Rectangle(float sideA, float sideB) 
{
	m_sideA = sideA;
	m_sideB = sideB;
}

float Rectangle::getPerimeter()
{
	return (2 * m_sideA + 2 * m_sideB);
}

float Rectangle::getArea()
{
	return (m_sideA * m_sideB);
}