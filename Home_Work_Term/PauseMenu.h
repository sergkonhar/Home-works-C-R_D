#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum class pauseMenyState
{
	Continue,
	ExitToMain,
	ExitGame,
	None
};

class PauseMenu 
{
public:

	PauseMenu();

	pauseMenyState processMenu(sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);


private:
	sf::Font m_font;
	sf::Text m_menuContinue;
	sf::Text m_menuExitGame;
	sf::Text m_menuReturnToMain;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	sf::RenderStates blendMode;
};
