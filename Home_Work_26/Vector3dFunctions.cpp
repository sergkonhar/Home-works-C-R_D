#include "Vector3d.h"
#include <string>

int Vector3d::instanceCount = 0;

Vector3d::Vector3d() 
	:m_StartX_axis(0.f), m_StartY_axis(0.f), m_StartZ_axis(0.f), m_EndX_axis(0.f), m_EndY_axis(0.f), m_EndZ_axis(0.f)
{
	instanceCount++;
}

Vector3d::Vector3d(float endX_axis, float endY_axis, float endZ_axis, float startX_axis, float startY_axis, float startZ_axis)
{
	 instanceCount++;
	 m_EndX_axis = endX_axis;
	 m_EndY_axis = endY_axis;
	 m_EndZ_axis = endZ_axis; 
	 m_StartX_axis = startX_axis;
	 m_StartY_axis = startY_axis;
	 m_StartZ_axis = startZ_axis;
}

Vector3d::~Vector3d() 
{
	instanceCount--;
}

std::string Vector3d::getCoordinates() 
{
	std::string vectorCordinates;
	vectorCordinates += "{";
	vectorCordinates += std::to_string(m_EndX_axis) + ", ";
	vectorCordinates += std::to_string(m_EndY_axis) + ", ";
	vectorCordinates += std::to_string(m_EndZ_axis) + ", ";
	vectorCordinates += std::to_string(m_StartX_axis) + ", ";
	vectorCordinates += std::to_string(m_StartY_axis) + ", ";
	vectorCordinates += std::to_string(m_StartZ_axis) + " ";
	vectorCordinates += "}";

	return vectorCordinates;
}

float Vector3d::getEndXValue() const
{
	return m_EndX_axis;
}

float Vector3d::getEndYValue() const
{
	return m_EndY_axis;
}

float Vector3d::getEndZValue() const
{
	return m_EndZ_axis;
}

float Vector3d::getStartXValue() const 
{
	return m_StartX_axis;
}

float Vector3d::getStartYValue() const 
{
	return m_StartY_axis;
}

float Vector3d::getStartZValue() const 
{
	return m_StartZ_axis;
}

Vector3d Vector3d::crossProduct(Vector3d& other)
{
	float firstStartXParameter = this->getEndXValue() - this->getStartXValue();
	float firstStartYParameter = this->getEndYValue() - this->getStartYValue();
	float firstStartZParameter = this->getEndZValue() - this->getStartZValue();
	float secondStartXParameter = other.getEndXValue() - other.getStartXValue();
	float secondStartYParameter = other.getEndYValue() - other.getStartYValue();
	float secondStartZParameter = other.getEndZValue() - other.getStartZValue();

	float resultEndX = firstStartYParameter * secondStartZParameter - firstStartZParameter * secondStartYParameter;
	float resultEndY = firstStartZParameter * secondStartXParameter - firstStartXParameter * secondStartZParameter;
	float resultEndZ = firstStartXParameter * secondStartYParameter - firstStartYParameter * secondStartXParameter;

	Vector3d resultingVector(resultEndX, resultEndY, resultEndZ, 0.f, 0.f, 0.f);

	return resultingVector;
}