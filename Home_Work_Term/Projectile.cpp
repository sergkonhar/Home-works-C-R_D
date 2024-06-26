#include "Projectile.h"


SingleGreen::SingleGreen() 
{
	m_laserTexture.loadFromFile("GreenBeam.png");
	m_beam.setTexture(m_laserTexture);
	sf::FloatRect bounds = m_beam.getLocalBounds();
	m_beam.setOrigin(bounds.width / 2.f, bounds.height);

	m_speed = 0.2f;
	m_active = true;
}

void SingleGreen::setInitialPosition(float x, float y)
{
	m_beam.setPosition(x, y);
}

void SingleGreen::fly()
{
	m_beam.move(0.f, -m_speed);
}

void SingleGreen::draw(sf::RenderWindow& window)
{
	if (m_active) 
	{
		window.draw(m_beam);
	}
	
}

bool SingleGreen::notOnTheScreen()
{
	if (m_beam.getPosition().y < -50.f)
	{
		return true;
	}

	return false;
}

sf::Sprite* SingleGreen::getSprite() 
{
	return &m_beam;
}


bool SingleGreen::getActivityStatus() 
{
	return m_active;
}

void SingleGreen::setInactive() 
{
	m_active = false;
}
