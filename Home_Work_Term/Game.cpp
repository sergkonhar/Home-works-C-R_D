#include "Game.h"
#include <iostream>
#include "Projectile.h"

Game::Game() 
{
	m_backTexture.loadFromFile("gameBack.jpg");
	m_backSprite.setTexture(m_backTexture);

}

void Game::setplayersProjectiles(Projectile* playersProjectile)
{
	m_playersProjectiles.push_back(playersProjectile);
}

void Game::processPlayersProjectileFly()
{
	if (m_playersProjectiles.size() > 0) 
	{
		for (int i = 0; i < m_playersProjectiles.size(); i++)
		{
			m_playersProjectiles[i]->fly();
		}


		auto it = m_playersProjectiles.begin();
		while (it != m_playersProjectiles.end())
		{
			(*it)->fly();
			if ((*it)->notOnTheScreen())
			{
				delete* it;
				it = m_playersProjectiles.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}

void Game::draw(sf::RenderWindow& window)
{
	if (m_playersProjectiles.size() > 0)
	{
		for (int i = 0; i < m_playersProjectiles.size(); i++)
		{
			m_playersProjectiles[i]->draw(window);
		}
	}
}

void Game::Run(sf::Event& event, sf::RenderWindow& window)
{
	pauseMenyState pauseState;
	pauseState = pauseMenyState::None;

	while (pauseState!= pauseMenyState::ExitToMain)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Escape)
				{
					pauseState = m_PauseMenu.processMenu(event, window);
				}
			}

			m_playerSpaceShip.shoot(event, window, *this);
		}

		m_stars.updatePosition();
		m_playerSpaceShip.handleMove();
		processPlayersProjectileFly();
		m_inGameHud.updateHP(m_playerSpaceShip);
		
		window.clear();

		window.draw(m_backSprite);
		m_stars.draw(window);
		draw(window);
		m_playerSpaceShip.draw(window);
		m_inGameHud.draw(window);

		window.display();
	}
}



