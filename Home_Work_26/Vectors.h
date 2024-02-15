#pragma once
#include <iostream>

enum class VectorRelativeState
{
	Identical,
	coDirected,
	OppositeDirected,
	AcuteAngle,
	ObtuseAngle,
	RightAngle
};

class Vector2d
{
public:

	Vector2d();
	Vector2d(float endX_axis, float endY_axis, float startX_axis, float startY_axis);

	~Vector2d();

	static int getInstanceCount();

	Vector2d& operator= (Vector2d& inVector);
	Vector2d& operator+(Vector2d& secondVector);
	Vector2d& operator-(Vector2d& secondVector);
	float operator()();
	float& operator[](int iterator);

	float getEndXValue() const;
	float getEndYValue() const;
	float getStartXValue() const;
	float getStartYValue() const;

	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);
	friend void operator >>(std::istream& in, Vector2d& vector);

	float dotProduct(Vector2d& other) const;
	float getLength() const;
	VectorRelativeState getRelativeState(Vector2d& other) const;
	
	Vector2d negate() const;

	void scale(float factorX, float factorY);

private:
	static int instanceCount;
	float m_EndX_axis;
	float m_EndY_axis;
	float m_StartX_axis;
	float m_StartY_axis;
	
};

std::ostream& operator<<(std::ostream& out, Vector2d& vector);
void operator >>(std::istream& in, Vector2d& vector);

