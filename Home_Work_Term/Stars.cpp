#include "Stars.h"
#include <iostream>
#include <cstdlib> 
#include <random>

Stars::Stars() 
{
	m_starTexture1.loadFromFile("star.png");
	m_starTexture2.loadFromFile("star1.png");
	m_starTexture3.loadFromFile("star2.png");
	m_starTexture4.loadFromFile("star3.png");
	m_starTexture5.loadFromFile("star4.png");
	m_starTexture6.loadFromFile("star5.png");
	m_starTexture7.loadFromFile("star6.png");
	m_starTexture8.loadFromFile("star7.png");

	m_star1.setTexture(m_starTexture3);
	m_star2.setTexture(m_starTexture8);
	m_star3.setTexture(m_starTexture3);
	m_star4.setTexture(m_starTexture8);
	m_star5.setTexture(m_starTexture4);
	m_star6.setTexture(m_starTexture8);
	m_star7.setTexture(m_starTexture4);
	m_star8.setTexture(m_starTexture8);
	m_star9.setTexture(m_starTexture8);
	m_star10.setTexture(m_starTexture3);
	m_star11.setTexture(m_starTexture3);
	m_star12.setTexture(m_starTexture4);
	m_star13.setTexture(m_starTexture4);
	m_star14.setTexture(m_starTexture3);
	m_star15.setTexture(m_starTexture4);
	
	m_stars.push_back(m_star1);
	m_stars.push_back(m_star2);
	m_stars.push_back(m_star3);
	m_stars.push_back(m_star4);
	m_stars.push_back(m_star5);
	m_stars.push_back(m_star6);
	m_stars.push_back(m_star7);
	m_stars.push_back(m_star8);
	m_stars.push_back(m_star9);
	m_stars.push_back(m_star10);
	m_stars.push_back(m_star11);
	m_stars.push_back(m_star12);
	m_stars.push_back(m_star13);
	m_stars.push_back(m_star14);
	m_stars.push_back(m_star15);

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	unsigned int screenWidth = desktop.width;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distributionX(0, screenWidth);
	std::uniform_int_distribution<int> distributionY(-850, -50);
	std::uniform_real_distribution<float> distributionScale(0.2f, 0.4f);

	for (int i = 0; i < m_stars.size(); i++)
	{
		
		int randomNumberX = distributionX(gen);
		int randomNumberY = distributionY(gen);
		float randomScale = distributionScale(gen);
		m_stars[i].setPosition(randomNumberX, randomNumberY);
		m_stars[i].setScale(randomScale, randomScale);

	}
}

void Stars::updatePosition()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	unsigned int screenWidth = desktop.width;
	unsigned int screenHeight = desktop.height;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distributionX(0, screenWidth);
	std::uniform_int_distribution<int> distributionY(-850, -50);
	std::uniform_real_distribution<float> distributionScale(0.2f, 0.4f);

	for (int i = 0; i < m_stars.size(); i++)
	{
		if (m_stars[i].getPosition().y >= screenHeight)
		{
			int randomNumberX = distributionX(gen);
			int randomNumberY = distributionY(gen);
			float randomScale = distributionScale(gen);
			m_stars[i].setPosition(randomNumberX, randomNumberY);
			m_stars[i].setScale(randomScale, randomScale);
		}
		else
		{
			m_stars[i].move(0, m_moveValue);
		}

	}
}

void Stars::draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < m_stars.size(); i++)
	{
		window.draw(m_stars[i]);
	}
}