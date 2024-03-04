#include "Player.h"
#include <cstdlib> 
#include <random>
#include <iostream>
#include "Game.h"


playerSpaceShip::playerSpaceShip() 
{
	
    m_ship.loadFromFile("PlayerShip.png");
    m_thruster.loadFromFile("thruster.png");

    m_spriteThrusterLeft.setTexture(m_thruster);
    m_spriteThrusterRigth.setTexture(m_thruster);

    sf::FloatRect bounds_thrusterLeft = m_spriteThrusterLeft.getLocalBounds();
    sf::FloatRect bounds_thrusterRigth = m_spriteThrusterRigth.getLocalBounds();

    m_spriteThrusterLeft.setOrigin(bounds_thrusterLeft.width / 2.f, 0);
    m_spriteThrusterRigth.setOrigin(bounds_thrusterRigth.width / 2.f, 0);

    m_spriteThrusterLeft.setPosition(789, 550);
    m_spriteThrusterRigth.setPosition(813, 550);

	m_sprite.setTexture(m_ship);
	m_sprite.setPosition(800, 500);
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    m_weapon = new GreenLaser;
    m_maxFramesToDrawShootBlink = 1000;
    m_currentDrawedFrames = 0;
    m_drawShootBlink = false;

    m_healthCurrent = 3;
    m_healthMax = 5;
    m_score = 0;
}

void playerSpaceShip::handleMove()
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (m_sprite.getPosition().x>=50)
        {
            move(-m_movementSpeed, 0);
        }
          
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (m_sprite.getPosition().x<= screenWidth-50)
        {
            move(m_movementSpeed, 0);
        }
       
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (m_sprite.getPosition().y>=50)
        {
            move(0, -m_movementSpeed);
        }
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (m_sprite.getPosition().y<= screenHeight-50)
        {
            move(0, m_movementSpeed);
        }
        
    }
}

void playerSpaceShip::move(float offsetX, float offsetY)
{
    m_sprite.move(offsetX, offsetY);
    m_spriteThrusterLeft.move(offsetX, offsetY);
    m_spriteThrusterRigth.move(offsetX, offsetY);
}

void playerSpaceShip::thrusterBlink()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distributionScale(0.8f, 1.f);
    float randomScale = distributionScale(gen);

    m_spriteThrusterLeft.setScale(1.f, randomScale);
    m_spriteThrusterRigth.setScale(1.f, randomScale);
}

void playerSpaceShip::draw(sf::RenderWindow& window)
{
    thrusterBlink();
    if (m_drawShootBlink)
    {
        if (m_currentDrawedFrames < m_maxFramesToDrawShootBlink) 
        {
            m_weapon->setBlinkposition(*this);
            m_weapon->draw(window);
            m_currentDrawedFrames++;
        }
        else if (m_currentDrawedFrames >= m_maxFramesToDrawShootBlink) 
        {
            m_drawShootBlink = false;
        }
    }
    window.draw(m_spriteThrusterLeft);
    window.draw(m_spriteThrusterRigth);
    window.draw(m_sprite);
   
}

sf::FloatRect playerSpaceShip::getGlobalPosition()
{
    sf::FloatRect globalPosition = m_sprite.getGlobalBounds();

    return globalPosition;
}

void playerSpaceShip::shoot(sf::Event& event, sf::RenderWindow& windowm, Game& currentGame)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
    {
		m_currentDrawedFrames = 0;
		m_drawShootBlink = true;
		
        currentGame.setplayersProjectiles(m_weapon->shoot(*this));
	}
}

int playerSpaceShip::getCurrentHP()
{
    return m_healthCurrent;
}

int playerSpaceShip::getMaxHP()
{
    return m_healthMax;

}
