#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Weapon.h"
#include "Projectile.h"

class Game;

class playerSpaceShip 
{
public:

    playerSpaceShip();

    void move(float offsetX, float offsetY);

    void handleMove();

    void draw(sf::RenderWindow& window);

    void thrusterBlink();

    sf::FloatRect getGlobalPosition();

    void shoot(sf::Event& event, sf::RenderWindow& windowm, Game& currentGame); 

    void setScore(int score);
    int getScore();

    void decreaseHP();
    void increaseHP();

    int getCurrentHP();
    int getMaxHP();
   

private:
    sf::Texture m_ship;
    sf::Texture m_thruster;
    sf::Sprite m_sprite;
    sf::Sprite m_spriteThrusterLeft;
    sf::Sprite m_spriteThrusterRigth;
    float m_movementSpeed = 0.1f; 

    Weapon* m_weapon;

    int m_maxFramesToDrawShootBlink;
    int m_currentDrawedFrames;
    bool m_drawShootBlink;

    int m_healthCurrent;
    int m_healthMax;
    int m_score;
};