#include "MainMenu.h"

mainMenu::mainMenu() 
{
	m_font.loadFromFile("arial.ttf");

	m_menuStartGame.setString("Start Game");
	m_menuStartGame.setFont(m_font);
	m_menuStartGame.setCharacterSize(50);
	m_menuStartGame.setFillColor(sf::Color::White);
	m_menuStartGame.setStyle(sf::Text::Bold);
	m_menuStartGame.setPosition(800, 300);

	m_menuExitGame.setString("Exit");
	m_menuExitGame.setFont(m_font);
	m_menuExitGame.setCharacterSize(50);
	m_menuExitGame.setFillColor(sf::Color::White);
	m_menuExitGame.setStyle(sf::Text::Bold);
	m_menuExitGame.setPosition(800, 370);

	m_title.setString("Pew-Pew Master");
	m_title.setFont(m_font);
	m_title.setCharacterSize(80);
	m_title.setFillColor(sf::Color::Green);
	m_title.setStyle(sf::Text::Bold);
	m_title.setPosition(650, 100);


	m_backgroundTexture.loadFromFile("mainMenuBack.jpg");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	
}

menuState mainMenu::inputHandler(sf::Event& event)
{
	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (m_menuStartGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				return menuState::startGame;
			}
			else if (m_menuExitGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				return menuState::exit;
			}
		}
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Key::Escape)
		{
			return menuState::exit;
		}
	}
	

}

void mainMenu::draw(sf::RenderWindow& window) 
{
	window.draw(m_backgroundSprite);
	window.draw(m_menuStartGame);
	window.draw(m_menuExitGame);
	window.draw(m_title);
}




