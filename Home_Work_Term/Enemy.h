#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Explode.h"
#include <SFML/Audio.hpp>


class playerSpaceShip;

class enemySpaceShip 
{
public:
    
    void autoMove();
    void setStartPosition(float x, float y);
    int getScore();
    sf::FloatRect getGlobalPosition();
    void decreaseHP(playerSpaceShip& player);
    void instantDestruction(playerSpaceShip& player);
    bool notOnTheScreen();
    void setExplotionPosition();

    enemySpaceShip* getEnemy();
    virtual sf::Sprite* getSprite() = 0;
    bool isDestroyed();

    virtual void draw(sf::RenderWindow& window)=0;
   
protected:
	sf::Texture m_ship;
	sf::Sprite m_sprite;

	int m_currentHP;
    float m_autoMoveSpeed;
    int m_scoreForDestruction;

    bool m_destroyed;

   Explode m_explodeEnemy;

   bool m_explotionDraw;

   sf::Music m_explosionSound;
};

class smallFastShip : public enemySpaceShip 
{
public:
    smallFastShip();


  
    sf::Sprite* getSprite();
    void draw(sf::RenderWindow& window) override;

};


