
class Rectangle 
{
public:
	Rectangle();
	Rectangle(float sideA, float sideB);
	float getPerimeter();
	float getArea();
	
	float getSideA();
	float getSideB();

private:
	float m_sideA = 0;
	float m_sideB = 0;
};
