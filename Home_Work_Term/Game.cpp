#include "Game.h"
#include <iostream>
#include "Projectile.h"
#include <cstdlib> 
#include <random>

Game::Game() 
{
	m_backTexture.loadFromFile("gameBack.jpg");
	m_backSprite.setTexture(m_backTexture);

	smallShipSpawnPeriod_Cycles = 5000;
	smallShipSpawnCyclesPassed = 0;

	m_battleMusic.openFromFile("battleMusic.wav");
	m_battleMusic.setLoop(true);
	m_battleMusic.setVolume(50);

	m_GameOver.openFromFile("gameover.wav");
	m_GameOver.setLoop(false);
	m_GameOver.setVolume(50);

}

void Game::setplayersProjectiles(Projectile* playersProjectile)
{
	m_playersProjectiles.push_back(playersProjectile);
}

void Game::processPlayersProjectileFly()
{
	if (m_playersProjectiles.size() > 0) 
	{
		
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

	if (m_enemyShips.size() > 0)
	{
		for (int i = 0; i < m_enemyShips.size(); i++)
		{
			m_enemyShips[i]->draw(window);
		}
	}

}

void Game::generateEnemy()
{
	smallShipSpawnCyclesPassed++;
	if (smallShipSpawnCyclesPassed>= smallShipSpawnPeriod_Cycles)
	{
		enemySpaceShip* generatedEnemy = new smallFastShip;

		sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
		unsigned int screenWidth = desktopMode.width;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distributionY(-650, -150);
		std::uniform_int_distribution<int> distributionX(150, screenWidth-150);
		int randomY = distributionY(gen);
		int randomX = distributionX(gen);

		generatedEnemy->setStartPosition(randomX, randomY);

		m_enemyShips.push_back(generatedEnemy);
		smallShipSpawnCyclesPassed = 0;
	}
}

void Game::processEnemyFly()
{
	if (m_enemyShips.size() > 0)
	{
		auto it = m_enemyShips.begin();
		while (it != m_enemyShips.end())
		{
			(*it)->autoMove();
			if ((*it)->notOnTheScreen())
			{
				delete* it;
				it = m_enemyShips.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}

void Game::processGlobalColissions(playerSpaceShip& player, sf::RenderWindow& window)
{
	sf::FloatRect screenBounds(0, 0, window.getSize().x, window.getSize().y);

	if (m_playersProjectiles.size() > 0 && m_enemyShips.size() > 0)
	{
	
 		for (int i = 0; i < m_playersProjectiles.size(); i++)
		{
			if (m_playersProjectiles[i]->getActivityStatus())
			{
			
				sf::FloatRect projectileSpriteBounds = m_playersProjectiles[i]->getSprite()->getGlobalBounds();
				if (screenBounds.intersects(projectileSpriteBounds))
				{
					
					for (int j = 0; j < m_enemyShips.size(); j++)
					{
						if (!m_enemyShips[j]->isDestroyed())
						{
							
							sf::FloatRect enemySpriteBounds = m_enemyShips[j]->getSprite()->getGlobalBounds();
							if (screenBounds.intersects(enemySpriteBounds))
							{
								if (projectileSpriteBounds.intersects(enemySpriteBounds))
								{
									
									m_enemyShips[j]->decreaseHP(player);
									m_playersProjectiles[i]->setInactive();
								}
								else if (enemySpriteBounds.intersects(player.getSprite()->getGlobalBounds()))
								{
									m_enemyShips[j]->instantDestruction(player);
									player.decreaseHP();

								}
							}
						}
					}
				}
			}
		}
	}

	if (m_enemyShips.size() > 0)
	{
		sf::FloatRect screenBounds(0, 0, window.getSize().x, window.getSize().y);
		sf::FloatRect playerBounds = player.getSprite()->getGlobalBounds();
		for (int j = 0; j < m_enemyShips.size(); j++)
		{
			if (!m_enemyShips[j]->isDestroyed())
			{

				sf::FloatRect enemySpriteBounds = m_enemyShips[j]->getSprite()->getGlobalBounds();
				if (screenBounds.intersects(enemySpriteBounds))
				{
					if (enemySpriteBounds.intersects(playerBounds))
					{
						m_enemyShips[j]->instantDestruction(player);
						player.decreaseHP();
					}
				}
			}
		}
	}
}

void Game::Run(sf::Event& event, sf::RenderWindow& window)
{
	m_battleMusic.play();
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

		generateEnemy();

		
		m_stars.updatePosition();
		m_playerSpaceShip.handleMove();
		processEnemyFly();
		processPlayersProjectileFly();
		m_inGameHud.updateHP(m_playerSpaceShip);
		m_inGameHud.updateScore(m_playerSpaceShip);
		
		window.clear();
		processGlobalColissions(m_playerSpaceShip, window);
		window.draw(m_backSprite);
		m_stars.draw(window);
		draw(window);
		m_playerSpaceShip.draw(window);
		m_inGameHud.draw(window);
		
		window.display();

		if (m_playerSpaceShip.getCurrentHP()<=0)
		{
			m_battleMusic.stop();

			m_GameOver.play();
			pauseState = gameOverMenu.processMenu(event, window, m_playerSpaceShip.getScore());
			m_GameOver.stop();
		}
	}
}




