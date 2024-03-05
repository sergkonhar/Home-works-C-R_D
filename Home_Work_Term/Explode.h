#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Explode 
{
public:
	Explode();

	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);

private:
	sf::Texture m_expTexture1;
	sf::Texture m_expTexture2;
	sf::Texture m_expTexture3;
	sf::Texture m_expTexture4;
	sf::Texture m_expTexture5;
	sf::Texture m_expTexture6;
	sf::Texture m_expTexture7;
	sf::Texture m_expTexture8;
	sf::Texture m_expTexture9;
	sf::Texture m_expTexture10;


	sf::Sprite m_Sprite1;
	sf::Sprite m_Sprite2;
	sf::Sprite m_Sprite3;
	sf::Sprite m_Sprite4;
	sf::Sprite m_Sprite5;
	sf::Sprite m_Sprite6;
	sf::Sprite m_Sprite7;
	sf::Sprite m_Sprite8;
	sf::Sprite m_Sprite9;
	sf::Sprite m_Sprite10;
	

	int m_currentFrameIndex;
	int m_endIndex;

	std::vector<sf::Sprite> m_ExplodeSprites;

	bool m_positionSet;
};
