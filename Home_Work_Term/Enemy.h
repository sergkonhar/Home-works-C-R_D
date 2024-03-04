#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class enemySpaceShip 
{
public:
    
    virtual void autoMove()=0;

    virtual void draw(sf::RenderWindow& window)=0;

    virtual void thrusterBlink()=0;

    virtual sf::FloatRect getGlobalPosition()=0;

    virtual int getScore()=0;

    virtual void decreaseHP()=0;

protected:
	sf::Texture m_ship;
	sf::Sprite m_sprite;

	int currentHP;
    float autoMoveSpeed;
    int scoreForDestruction;

};

class smallFastShip : public enemySpaceShip 
{
public:
    smallFastShip();

    void autoMove() override;

    void draw(sf::RenderWindow& window) override;

    void thrusterBlink() override;

    sf::FloatRect getGlobalPosition() override;

    int getScore() override;

    void decreaseHP() override;

};


