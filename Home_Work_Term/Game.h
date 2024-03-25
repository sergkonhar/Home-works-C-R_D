#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Stars.h"
#include "PauseMenu.h"
#include"Projectile.h"
#include <vector>
#include "InGameHUD.h"
#include "Enemy.h"
#include "GameOver.h"
#include <SFML/Audio.hpp>


class Game 
{
public:

	Game();

	void Run(sf::Event& event, sf::RenderWindow& window);
	void setplayersProjectiles(Projectile* playersProjectile);
	void processPlayersProjectileFly();
	void draw(sf::RenderWindow& window);
	void generateEnemy();
	void processEnemyFly();

	void processGlobalColissions(playerSpaceShip& player, sf::RenderWindow& window);

private:
	playerSpaceShip m_playerSpaceShip;
	sf::Texture m_backTexture;
	sf::Sprite m_backSprite;
	Stars m_stars;
	PauseMenu m_PauseMenu;
	std::vector<Projectile*> m_playersProjectiles;
	HUD m_inGameHud;
	std::vector<enemySpaceShip*> m_enemyShips;

	int smallShipSpawnPeriod_Cycles;
	int smallShipSpawnCyclesPassed;
	GameOver gameOverMenu;
	sf::Music m_battleMusic;
	sf::Music m_GameOver;
};


