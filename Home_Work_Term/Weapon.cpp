#include "Weapon.h"
#include "Player.h"  


GreenLaser::GreenLaser() 
{
	m_projectile = ProjectyleType::Single;

	m_blink.loadFromFile("greenBlink.png");
	m_blinkSprite.setTexture(m_blink);

	sf::FloatRect bounds = m_blinkSprite.getLocalBounds();
	m_blinkSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}


Projectile* GreenLaser::shoot(playerSpaceShip& playerShip)
{
	setBlinkposition(playerShip);
	m_ShootProjectile = new SingleGreen;

	float positionX = playerShip.getGlobalPosition().left;
	float positionY = playerShip.getGlobalPosition().top;

	m_ShootProjectile->setInitialPosition(positionX+100, positionY);

	return m_ShootProjectile;
}
	
void GreenLaser::setBlinkposition(playerSpaceShip& playerShip)
{
	float positionX = playerShip.getGlobalPosition().left;
	float positionY = playerShip.getGlobalPosition().top;

	m_blinkSprite.setPosition(positionX+100.f, positionY);
}

void GreenLaser::draw(sf::RenderWindow& window)
{
	window.draw(m_blinkSprite);
}

