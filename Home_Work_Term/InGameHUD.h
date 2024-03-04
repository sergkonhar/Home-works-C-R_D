#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include <vector>

class HUD 
{
public:

	HUD();

	void updateHP(playerSpaceShip& player);
	void draw(sf::RenderWindow& window);

private:
	sf::Font m_font;
	sf::Text m_HP_text;
	sf::Text m_scoreText;
	sf::Text m_controlText;

	sf::Texture m_HP_texture;
	sf::Sprite m_HP_sprite;

	sf::Texture m_HP_empty_texture;
	sf::Sprite m_HP_empty_sprite;

	sf::Texture m_Score_frame_texture;
	sf::Sprite m_Score_frame_sprite;

	float m_HPInitialPositionX;
	float m_HPInitialPositionY;
	float m_HPOffsetX;

	std::vector < sf::Sprite> emptyHP;
	std::vector < sf::Sprite> filledHP;

	int m_LastUpdated_MaxHP;
	int m_LastUpdated_CurrentHP;
};