#include "Enemy.h"
#include "Player.h"
#include <iostream>

void enemySpaceShip::autoMove() 
{
	m_sprite.move(0, m_autoMoveSpeed);
}

void enemySpaceShip::setStartPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

int enemySpaceShip::getScore() 
{
	return m_scoreForDestruction;
}

sf::FloatRect enemySpaceShip::getGlobalPosition()
{
	sf::FloatRect globalPosition = m_sprite.getGlobalBounds();

	return globalPosition;
}

void enemySpaceShip::decreaseHP(playerSpaceShip& player)
{
	m_currentHP -= 1;
	if (!m_destroyed)
	{
		if (m_currentHP <= 0)
		{
			m_destroyed = true;
			player.setScore(m_scoreForDestruction);
			setExplotionPosition();
		}
	}
	
}

void enemySpaceShip::instantDestruction(playerSpaceShip& player)
{
	m_currentHP = 0;
	if (!m_destroyed)
	{
		if (m_currentHP <= 0)
		{
			m_destroyed = true;
			player.setScore(m_scoreForDestruction);
			setExplotionPosition();
		}
	}
}

bool enemySpaceShip::notOnTheScreen()
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	unsigned int screenHeight = desktopMode.height;

	if (m_sprite.getPosition().y>= screenHeight+100.f)
	{
		return true;
	}

	return false;
}

enemySpaceShip* enemySpaceShip::getEnemy() 
{
	return this;
}

bool enemySpaceShip::isDestroyed()
{
	return m_destroyed;
}

void enemySpaceShip::setExplotionPosition()
{
	sf::FloatRect shipPosition = this->getGlobalPosition();
	float originX = this->getSprite()->getLocalBounds().width / 2.f;
	float originY = this->getSprite()->getLocalBounds().height / 2.f;
	float x = shipPosition.getPosition().x+ originX;
	float y = shipPosition.getPosition().y+ originY;

	m_explodeEnemy.setPosition(x, y);

}

smallFastShip::smallFastShip() 
{
	m_ship.loadFromFile("smallFastShip.png");
	m_sprite.setTexture(m_ship);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.f, m_sprite.getLocalBounds().height / 2.f);

	m_currentHP = 1;
	m_autoMoveSpeed = 0.15f;
	m_scoreForDestruction = 100;

	m_destroyed = false;
}

void smallFastShip::draw(sf::RenderWindow& window) 
{
	if (!m_destroyed)
	{
		window.draw(m_sprite);
	}
	else 
	{
		m_explodeEnemy.draw(window);
	}
}


sf::Sprite* smallFastShip::getSprite() 
{
	return &m_sprite;
}
