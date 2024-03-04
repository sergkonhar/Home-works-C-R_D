#include "Vectors.h"
#include <iostream>
#include <cmath>
#include <cmath>

#define MY_ASSERT(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << #condition << ", " << message << " in file " << __FILE__ \
                  << " at line " << __LINE__ << std::endl; \
        std::terminate(); \
    }

int Vector2d::instanceCount = 0;

const float pi = 3.14;



Vector2d::Vector2d()
	: m_EndX_axis(10.0), m_EndY_axis(10.0), m_StartX_axis(0.0), m_StartY_axis(0.0)
{
	instanceCount++;
}


Vector2d::Vector2d(float endX_axis, float endY_axis, float startX_axis, float startY_axis)
{
	m_EndX_axis = endX_axis;
	m_EndY_axis = endY_axis;
	m_StartX_axis = startX_axis;
	m_StartY_axis = startY_axis;
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

Vector2d& Vector2d::operator=(Vector2d& inVector)
{
	if (this == &inVector)
	{
		return *this;
	}
	this->m_EndX_axis = inVector.getEndXValue();
	this->m_EndY_axis = inVector.getEndYValue();
	this->m_StartX_axis = inVector.getStartXValue();
	this->m_StartY_axis = inVector.getStartYValue();
	return *this;
}


float Vector2d::getEndXValue() const
{
	return m_EndX_axis;
}

float Vector2d::getEndYValue() const
{
	return m_EndY_axis;
}

float Vector2d::getStartXValue() const
{
	return m_StartX_axis;
}

float Vector2d::getStartYValue() const
{
	return m_StartY_axis;
}

Vector2d& Vector2d::operator+( Vector2d& secondVector)
{
	float result_EndX_axis = this->getEndXValue() + secondVector.getEndXValue();
	float result_EndY_axis = this->getEndYValue() + secondVector.getEndYValue();
	float result_StartX_axis = this->getStartXValue() + secondVector.getStartXValue();
	float result_StartY_axis = this->getStartYValue() + secondVector.getStartYValue();

	return *(new Vector2d(result_EndX_axis, result_EndY_axis, result_StartX_axis, result_StartY_axis));
}

Vector2d& Vector2d::operator-(Vector2d& secondVector)
{
	float result_EndX_axis = this->getEndXValue() - secondVector.getEndXValue();
	float result_EndY_axis = this->getEndYValue() - secondVector.getEndYValue();
	float result_StartX_axis = this->getStartXValue() - secondVector.getStartXValue();
	float result_StartY_axis = this->getStartYValue() - secondVector.getStartYValue();

	return *(new Vector2d(result_EndX_axis, result_EndY_axis, result_StartX_axis, result_StartY_axis));
}

float Vector2d::operator()()
{
	float xLengthPowerofTwo = std::pow(this->getEndXValue() - this->getStartXValue(), 2);
	float yLengthPowerofTwo = std::pow(this->getEndYValue() - this->getStartYValue(), 2);

	float vectorLegth = std::sqrt(xLengthPowerofTwo + yLengthPowerofTwo);

	return vectorLegth;
}

float& Vector2d::operator[](int iterator)
{
	MY_ASSERT(iterator>=0 && iterator<4, "Wrong index")
	if (iterator == 0)
	{
		return this->m_EndX_axis;
	}

	else if (iterator == 1)
	{
		return this->m_EndY_axis;
	}
	else if (iterator == 2)
	{
		return this->m_StartX_axis;
	}
	else if (iterator == 3)
	{
		return this->m_StartY_axis;
	}
}

std::ostream& operator<<(std::ostream& out, Vector2d& vector)
{
	out << "Vector paramaters: {" << vector.m_EndX_axis << ", " << vector.m_EndY_axis << ", " << vector.m_StartX_axis << ", " << vector.m_StartY_axis <<  "}";
	return out;
}


void operator >>(std::istream& in, Vector2d& vector)
{
	in >> vector.m_EndX_axis;
	in >> vector.m_EndY_axis;
	in >> vector.m_StartX_axis;
	in >> vector.m_StartY_axis;
}


float Vector2d::dotProduct(Vector2d& other) const
{
	float firstStartXParameter = this->getEndXValue() - this->getStartXValue();
	float firstStartYParameter = this->getEndYValue() - this->getStartYValue();
	float secondStartXParameter = other.getEndXValue() - other.getStartXValue();
	float secondStartYParameter = other.getEndYValue() - other.getStartYValue();

	return firstStartXParameter * secondStartXParameter + firstStartYParameter * secondStartYParameter;
}

Vector2d Vector2d::negate() const 
{
	Vector2d* invertedVector = new Vector2d(-this->getEndXValue(), -this->getEndYValue(), -this->getStartXValue(), -this->getStartYValue());
	return  *invertedVector;
}

float Vector2d::getLength() const
{
	float xLengthPowerofTwo = std::pow(this->getEndXValue() - this->getStartXValue(), 2);
	float yLengthPowerofTwo = std::pow(this->getEndYValue() - this->getStartYValue(), 2);

	float vectorLegth = std::sqrt(xLengthPowerofTwo + yLengthPowerofTwo);

	return vectorLegth;
}

VectorRelativeState Vector2d::getRelativeState(Vector2d& other) const
{
	float dotProduction = this->dotProduct(other);
	float firstVecLength = this->getLength();
	float secondVecLength = other.getLength();
	float cosTeta = dotProduction / (firstVecLength * secondVecLength);
	float arccosTeatRad = std::acos(dotProduction / (firstVecLength * secondVecLength));
	float arccosTeatDeg = arccosTeatRad * (180 / pi);

	bool endIdentical = (this->getEndXValue() == other.getEndXValue() && this->getEndYValue() == other.getEndYValue());
	bool startIdentical = (this->getStartXValue() == other.getStartXValue() && this->getStartYValue() == other.getStartYValue());

	if (endIdentical&& startIdentical)
	{
		return VectorRelativeState::Identical;
	}
	
	else if (cosTeta==1)
	{
		return VectorRelativeState::coDirected;
	}

	else if (cosTeta == -1)
	{
		return VectorRelativeState::OppositeDirected;
	}

	else if (cosTeta == 0)
	{
		return VectorRelativeState::RightAngle;
	}

	else if (arccosTeatDeg < 90)
	{
		return VectorRelativeState::AcuteAngle;
	}
	
	else if (arccosTeatDeg > 90)
	{
		return VectorRelativeState::ObtuseAngle;
	}
}

void Vector2d::scale(float factorX, float factorY)
{
	m_EndX_axis = m_EndX_axis * factorX;
	m_EndY_axis = m_EndY_axis * factorY;
}

