#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class menuState 
{
	startGame,
	exit
};

class mainMenu 
{
public:

	mainMenu();

	menuState inputHandler(sf::Event& event);
	
	void draw(sf::RenderWindow& window);
	
private:
	sf::Font m_font;
	sf::Text m_menuStartGame;
	sf::Text m_menuExitGame;
	sf::Text m_title;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};