#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Enemy.h"



class Projectile 
{
public:

	virtual void setInitialPosition(float x, float y) = 0;
	virtual void fly()=0;
	virtual void draw(sf::RenderWindow& window)=0;
	virtual bool notOnTheScreen() = 0;

	virtual bool getActivityStatus()=0;
	virtual void setInactive() =0;

	virtual sf::Sprite* getSprite() = 0;
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
	bool notOnTheScreen() override;

	bool getActivityStatus() override;
	void setInactive() override;

	sf::Sprite* getSprite() override;
	

protected:
	sf::Sprite m_beam;
	bool m_active;
};