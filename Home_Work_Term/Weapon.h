#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Projectile.h"
#include <SFML/Audio.hpp>

class playerSpaceShip;

enum class ProjectyleType
{
	Single,
	Double,
	TriWay,
	Ray

};

class Weapon 
{
public:

	virtual Projectile* shoot(playerSpaceShip& playerShip)=0;
	virtual void setBlinkposition(playerSpaceShip& playerShip) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	ProjectyleType m_projectile;
	sf::Texture m_blink;
	sf::Sprite m_blinkSprite;
};

class GreenLaser : public Weapon
{
public:

	GreenLaser();
	Projectile* shoot(playerSpaceShip& playerShip) override;
	void setBlinkposition(playerSpaceShip& playerShip) override;
	void draw(sf::RenderWindow& window) override;

private:
	Projectile* m_ShootProjectile;
	sf::Music m_shootSound;
};





