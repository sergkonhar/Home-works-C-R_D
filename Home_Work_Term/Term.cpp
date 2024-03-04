#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode::getDesktopMode(), "Game");
	
	mainMenu startMenu;
	sf::Event event;

	while (mainWindow.isOpen())
	{
		
		
		while (mainWindow.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
			{
				mainWindow.close();
			}

			if (startMenu.inputHandler(event) == menuState::exit) 
			{
				mainWindow.close();
			}

			else if (startMenu.inputHandler(event) == menuState::startGame)
			{
				Game game;
				game.Run(event, mainWindow);
					
			}
		}

		mainWindow.clear();
		startMenu.draw(mainWindow);
		mainWindow.display();

	}
	
}