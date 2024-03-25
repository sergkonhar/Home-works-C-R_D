#include "InGameHUD.h"
#include <iostream>
#include <string>

HUD::HUD()
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	unsigned int screenWidth = desktopMode.width;
	unsigned int screenHeight = desktopMode.height;

	m_font.loadFromFile("arial.ttf");
	m_HP_text.setFont(m_font);
	m_scoreText.setFont(m_font);
	m_controlText.setFont(m_font);
	m_currentScore.setFont(m_font);

	m_HP_text.setString("HP");
	m_HP_text.setCharacterSize(30);
	m_HP_text.setOrigin(m_HP_text.getLocalBounds().width / 2.f, m_HP_text.getLocalBounds().height / 2.f);
	m_HP_text.setPosition(50, 50);
	
	m_scoreText.setString("Score");
	m_scoreText.setCharacterSize(30);
	m_scoreText.setOrigin(m_scoreText.getLocalBounds().width / 2.f, m_scoreText.getLocalBounds().height / 2.f);
	m_scoreText.setPosition(screenWidth-300, 50);

	m_controlText.setString("Use Arrows To Fly In Different Directions, Use Space To Shoot");
	m_controlText.setCharacterSize(20);
	m_controlText.setOrigin(m_controlText.getLocalBounds().width / 2.f, m_controlText.getLocalBounds().height / 2.f);
	m_controlText.setPosition(screenWidth/2, screenHeight-100);

	m_currentScore.setString("000000000");
	m_currentScore.setCharacterSize(20);
	m_currentScore.setOrigin(m_controlText.getLocalBounds().width / 2.f, m_controlText.getLocalBounds().height / 2.f);
	m_currentScore.setPosition(screenWidth+90, 56);

	m_HP_texture.loadFromFile("HP.png");
	m_HP_sprite.setTexture(m_HP_texture);
	m_HP_sprite.setOrigin(m_HP_sprite.getLocalBounds().width / 2.f, m_HP_sprite.getLocalBounds().height / 2.f);
	m_HP_sprite.setScale(0.8f, 0.8f);

	m_HP_empty_texture.loadFromFile("HPFreame.png");
	m_HP_empty_sprite.setTexture(m_HP_empty_texture);
	m_HP_empty_sprite.setOrigin(m_HP_empty_sprite.getLocalBounds().width / 2.f, m_HP_empty_sprite.getLocalBounds().height / 2.f);
	m_HP_empty_sprite.setScale(0.8f, 0.8f);
	

	m_Score_frame_texture.loadFromFile("Frame.png");
	m_Score_frame_sprite.setTexture(m_Score_frame_texture);
	m_Score_frame_sprite.setOrigin(m_Score_frame_sprite.getLocalBounds().width / 2.f, m_Score_frame_sprite.getLocalBounds().height / 2.f);
	m_Score_frame_sprite.setScale(1.4f, 0.6f);
	m_Score_frame_sprite.setPosition(screenWidth - 140,58);

	m_HPInitialPositionX = 100.f;
	m_HPInitialPositionY = 58.f;
	m_HPOffsetX = 40.f;

	m_LastUpdated_MaxHP = 0;
	m_LastUpdated_CurrentHP = 0;
	m_lastUpdatedScore = 0;
}

void HUD::updateHP(playerSpaceShip& player)
{
	int currentHP = player.getCurrentHP();
	int maxHP = player.getMaxHP();

	if (maxHP != m_LastUpdated_MaxHP) 
	{
		emptyHP.clear();
		for (int i = 0; i < maxHP; i++)
		{
			m_HP_empty_sprite.setPosition(m_HPInitialPositionX + i * m_HPOffsetX, m_HPInitialPositionY);
			emptyHP.push_back(m_HP_empty_sprite);
		}
		m_LastUpdated_MaxHP = maxHP;
	}
	
	if (currentHP != m_LastUpdated_CurrentHP)
	{
		filledHP.clear();
		for (int i = 0; i < currentHP; i++)
		{
			m_HP_sprite.setPosition(m_HPInitialPositionX + i * m_HPOffsetX, m_HPInitialPositionY);
			filledHP.push_back(m_HP_sprite);
		}
		m_LastUpdated_CurrentHP = currentHP;
	}
	
}

void HUD::updateScore(playerSpaceShip& player)
{
	int currentScore = player.getScore();
	
	if (currentScore != m_lastUpdatedScore)
	{
		std::string scoreString = std::to_string(currentScore);
		while (scoreString.length() < 9) 
		{
			scoreString = "0" + scoreString;
		}

		m_lastUpdatedScore = currentScore;

		m_currentScore.setString(scoreString);
	}
}



void HUD::draw(sf::RenderWindow& window)
{
	window.draw(m_HP_text);
	window.draw(m_scoreText);
	window.draw(m_controlText);
	
	for (int i = 0; i < emptyHP.size(); i++)
	{
		window.draw(emptyHP[i]);
	}

	for (int i = 0; i < filledHP.size(); i++)
	{
		window.draw(filledHP[i]);
	}

	window.draw(m_Score_frame_sprite);
	window.draw(m_currentScore);
	
}







