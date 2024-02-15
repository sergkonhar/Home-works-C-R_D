#pragma once
#include <string>

class Vector3d
{
public:

	Vector3d();
	Vector3d(float endX_axis, float endY_axis, float endZ_axis, float startX_axis, float startY_axis, float startZ_axis);

	~Vector3d();

	Vector3d crossProduct(Vector3d& other);
	std::string getCoordinates();

	float getEndXValue() const;
	float getEndYValue() const;
	float getEndZValue() const;
	float getStartXValue() const;
	float getStartYValue() const;
	float getStartZValue() const;

private:
	static int instanceCount;
	float m_EndX_axis;
	float m_EndY_axis;
	float m_EndZ_axis;
	float m_StartX_axis;
	float m_StartY_axis;
	float m_StartZ_axis;
	
};