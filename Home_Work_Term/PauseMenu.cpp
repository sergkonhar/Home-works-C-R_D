#include "PauseMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>


PauseMenu::PauseMenu() 
{
	m_font.loadFromFile("arial.ttf");
	
	m_menuContinue.setString("Continue");
	m_menuExitGame.setString("Exit Game");
	m_menuReturnToMain.setString("Exit To Main Menu");

	m_menuContinue.setFont(m_font);
	m_menuExitGame.setFont(m_font);
	m_menuReturnToMain.setFont(m_font);

	m_menuContinue.setCharacterSize(50);
	m_menuExitGame.setCharacterSize(50);
	m_menuReturnToMain.setCharacterSize(50);

	m_menuContinue.setFillColor(sf::Color::White);
	m_menuExitGame.setFillColor(sf::Color::White);
	m_menuReturnToMain.setFillColor(sf::Color::White);

	m_menuContinue.setStyle(sf::Text::Bold);
	m_menuExitGame.setStyle(sf::Text::Bold);
	m_menuReturnToMain.setStyle(sf::Text::Bold);

	m_menuContinue.setPosition(800, 300);
	m_menuExitGame.setPosition(800, 440);
	m_menuReturnToMain.setPosition(800, 370);

	m_backgroundTexture.loadFromFile("pauseBack.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setColor(sf::Color(128, 128, 128, 30));

	blendMode.blendMode = sf::BlendMax;
	
}


void PauseMenu::draw(sf::RenderWindow& window) 
{
	window.draw(m_backgroundSprite, blendMode);
	window.draw(m_menuContinue);
	window.draw(m_menuExitGame);
	window.draw(m_menuReturnToMain);
}

pauseMenyState PauseMenu::processMenu(sf::Event& event, sf::RenderWindow& window)
{
	while (true)
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();	
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (m_menuContinue.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						return pauseMenyState::Continue;
					}
					else if (m_menuExitGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						window.close();
						return pauseMenyState::ExitGame;
					}
					else if (m_menuReturnToMain.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						return pauseMenyState::ExitToMain;
					}
				}
			}
			else if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Key::Escape)
				{
					return pauseMenyState::Continue;
				}
			}
		}

		draw(window);
		window.display();
	}
}