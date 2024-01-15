#pragma once
#include <iostream>

class Vector2d
{
public:

	Vector2d();
	Vector2d(float X_axis, float Y_axis);

	~Vector2d();

	static int getInstanceCount();

	Vector2d& operator= (Vector2d& inVector);
	//Vector2d& operator+(Vector2d& secondVector);
	//Vector2d& operator-(Vector2d& secondVector);
	float operator()();
	float& operator[](int iterator);
	
	float getXValue();
	float getYValue();

	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);
	friend void operator >>(std::istream& in, Vector2d& vector);
	friend Vector2d operator+(Vector2d& firstVector, Vector2d& secondVector);
	friend Vector2d operator-(Vector2d& firstVector, Vector2d& secondVector);

private:
	static int instanceCount;
	float m_X_axis;
	float m_Y_axis;

};

std::ostream& operator<<(std::ostream& out, Vector2d& vector);
void operator >>(std::istream& in, Vector2d& vector);

Vector2d operator+(Vector2d& firstVector, Vector2d& secondVector);
Vector2d operator-(Vector2d& firstVector, Vector2d& secondVector);