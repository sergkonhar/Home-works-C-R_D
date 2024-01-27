#include "Vector.h"
#include <iostream>
#include <cmath>

 int Vector2d::instanceCount=0;

Vector2d::Vector2d() 
	: m_X_axis(10.0), m_Y_axis(10.0)
{
	instanceCount++;
}


Vector2d::Vector2d(float X_axis, float Y_axis)
{
	m_X_axis = X_axis;
	m_Y_axis = Y_axis;	
	instanceCount++;
}

Vector2d::~Vector2d()
{
	instanceCount--;
}

int Vector2d::getInstanceCount()
{
	return instanceCount;
}

Vector2d&  Vector2d::operator=(Vector2d& inVector)
{
	if (this == &inVector) 
	{
		return *this;
	}
	this->m_X_axis = inVector.getXValue();
	this->m_Y_axis = inVector.getYValue();
	return *this;
}


float Vector2d::getXValue() 
{
	return m_X_axis;
}

float Vector2d::getYValue() 
{
	return m_Y_axis;
}


//Vector2d& Vector2d::operator+( Vector2d& secondVector)
//{
//	return *(new Vector2d(this->getXValue() + secondVector.getXValue(), this->getYValue() + secondVector.getYValue()));
//}
//
//Vector2d& Vector2d::operator-(Vector2d& secondVector)
//{
//	return *(new Vector2d(this->getXValue() - secondVector.getXValue(), this->getYValue() - secondVector.getYValue()));
//}

float Vector2d::operator()()
{
	float xLengthPowerofTwo = std::pow(this->getXValue(), 2);
	float yLengthPowerofTwo = std::pow(this->getYValue(), 2);

	float vectorLegth = std::sqrt(xLengthPowerofTwo + yLengthPowerofTwo);

	return vectorLegth;
}

float& Vector2d::operator[](int iterator)
{
	if (iterator == 0) 
	{
		return this->m_X_axis;
	}

	else if (iterator == 1)
	{
		return this->m_Y_axis;
	}

	
}

std::ostream& operator<<(std::ostream& out, Vector2d& vector)
{
	out << "Vector paramaters: {" << vector.m_X_axis << ", " << vector.m_Y_axis << "}";
	return out;
}

Vector2d operator+(Vector2d& firstVector, Vector2d& secondVector) 
{
	return *(new Vector2d(firstVector.getXValue() + secondVector.getXValue(), firstVector.getYValue() + secondVector.getYValue());
}

Vector2d operator-(Vector2d& firstVector, Vector2d& secondVector) 
{
	return *(new Vector2d(firstVector.getXValue() - secondVector.getXValue(), firstVector.getYValue() - secondVector.getYValue()));
}

void operator >>(std::istream& in, Vector2d& vector) 
{
	in >> vector.m_X_axis;
	in >> vector.m_Y_axis;
}