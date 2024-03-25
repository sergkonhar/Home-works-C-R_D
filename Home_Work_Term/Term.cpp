#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode::getDesktopMode(), "Game");
	sf::Music musicMainMenu;
	musicMainMenu.openFromFile("musicMainMenu.wav");
	musicMainMenu.setLoop(true);
	musicMainMenu.setVolume(50);
	musicMainMenu.play();

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
				musicMainMenu.stop();
				Game game;
				game.Run(event, mainWindow);
				musicMainMenu.play();
			}
		}

		mainWindow.clear();
		startMenu.draw(mainWindow);
		mainWindow.display();

	}
	
}