#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Stars.h"
#include "PauseMenu.h"
#include"Projectile.h"
#include <vector>
#include "InGameHUD.h"

class Game 
{
public:

	Game();

	void Run(sf::Event& event, sf::RenderWindow& window);
	void setplayersProjectiles(Projectile* playersProjectile);
	void processPlayersProjectileFly();
	void draw(sf::RenderWindow& window);


private:
	playerSpaceShip m_playerSpaceShip;
	sf::Texture m_backTexture;
	sf::Sprite m_backSprite;
	Stars m_stars;
	PauseMenu m_PauseMenu;
	std::vector<Projectile*> m_playersProjectiles;
	HUD m_inGameHud;
};
