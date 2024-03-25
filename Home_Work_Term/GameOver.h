#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

enum class pauseMenyState;

class GameOver 
{
public:

	GameOver();
	void formScores(int scores);
	pauseMenyState processMenu(sf::Event& event, sf::RenderWindow& window, int scores);
	void draw(sf::RenderWindow& window);
	 

private:
	sf::Font m_font;
	sf::Text m_gameOverText;
	sf::Text m_scoreText;
	sf::Text m_controlText;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	sf::RenderStates blendMode;

	std::string m_scoreString;
	std::string m_score;
};