#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Stars 
{
public:
	Stars();

	void updatePosition();

	void draw(sf::RenderWindow& window);


private:
	sf::Texture m_starTexture1;
	sf::Texture m_starTexture2;
	sf::Texture m_starTexture3;
	sf::Texture m_starTexture4;
	sf::Texture m_starTexture5;
	sf::Texture m_starTexture6;
	sf::Texture m_starTexture7;
	sf::Texture m_starTexture8;

	sf::Sprite m_star1;
	sf::Sprite m_star2;
	sf::Sprite m_star3;
	sf::Sprite m_star4;
	sf::Sprite m_star5;
	sf::Sprite m_star6;
	sf::Sprite m_star7;
	sf::Sprite m_star8;
	sf::Sprite m_star9;
	sf::Sprite m_star10;
	sf::Sprite m_star11;
	sf::Sprite m_star12;
	sf::Sprite m_star13;
	sf::Sprite m_star14;
	sf::Sprite m_star15;

	std::vector<sf::Sprite> m_stars;
	float m_moveValue = 0.2f;
};