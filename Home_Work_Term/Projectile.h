#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>



class Projectile 
{
public:

	virtual void setInitialPosition(float x, float y) = 0;
	virtual void fly()=0;
	virtual void draw(sf::RenderWindow& window)=0;
	virtual void getCollision() =0;
	virtual bool notOnTheScreen() = 0;

	Projectile* getProjectile() { return this; };

protected:
	float m_speed;
	sf::Texture m_laserTexture;
};

class SingleGreen : public Projectile
{
public:
	SingleGreen();
	void setInitialPosition(float x, float y) override;
	void fly() override;
	void draw(sf::RenderWindow& window) override;
	void getCollision() override;
	bool notOnTheScreen() override;

protected:
	sf::Sprite m_beam;
};