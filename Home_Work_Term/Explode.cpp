#include "Explode.h"


Explode::Explode() 
{
	m_expTexture1.loadFromFile("Explode1.png");
	m_expTexture2.loadFromFile("Explode2.png");
	m_expTexture3.loadFromFile("Explode3.png");
	m_expTexture4.loadFromFile("Explode4.png");
	m_expTexture5.loadFromFile("Explode5.png");
	m_expTexture6.loadFromFile("Explode6.png");
	m_expTexture7.loadFromFile("Explode7.png");
	m_expTexture8.loadFromFile("Explode8.png");
	m_expTexture9.loadFromFile("Explode9.png");
	m_expTexture10.loadFromFile("Explode10.png");


	m_Sprite1.setTexture(m_expTexture1);
	m_Sprite2.setTexture(m_expTexture2);
	m_Sprite3.setTexture(m_expTexture3);
	m_Sprite4.setTexture(m_expTexture4);
	m_Sprite5.setTexture(m_expTexture5);
	m_Sprite6.setTexture(m_expTexture6);
	m_Sprite7.setTexture(m_expTexture7);
	m_Sprite8.setTexture(m_expTexture8);
	m_Sprite9.setTexture(m_expTexture9);
	m_Sprite10.setTexture(m_expTexture10);	

	m_ExplodeSprites.push_back(m_Sprite1);
	m_ExplodeSprites.push_back(m_Sprite2);
	m_ExplodeSprites.push_back(m_Sprite3);
	m_ExplodeSprites.push_back(m_Sprite4);
	m_ExplodeSprites.push_back(m_Sprite5);
	m_ExplodeSprites.push_back(m_Sprite6);
	m_ExplodeSprites.push_back(m_Sprite7);
	m_ExplodeSprites.push_back(m_Sprite8);
	m_ExplodeSprites.push_back(m_Sprite9);
	m_ExplodeSprites.push_back(m_Sprite10);
	


	for (int i = 0; i < m_ExplodeSprites.size(); i++)
	{
		m_ExplodeSprites[i].setOrigin(m_ExplodeSprites[i].getLocalBounds().width / 2.f, m_ExplodeSprites[i].getLocalBounds().height / 2.f);
		m_ExplodeSprites[i].setScale(1.f, 1.f);
	}

	m_currentFrameIndex = 0;
	m_endIndex = 10;

	m_positionSet = false;

}

void Explode::draw(sf::RenderWindow& window)
{
	if (m_currentFrameIndex < m_endIndex)
	{
		window.draw(m_ExplodeSprites[m_currentFrameIndex]);
		m_currentFrameIndex += 1;
		if (m_currentFrameIndex == 8) 
		{
			m_currentFrameIndex = 0;
		}
	}
}

void Explode::setPosition(float x, float y) 
{
	if (!m_positionSet)
	{
		for (int i = 0; i < m_ExplodeSprites.size(); i++)
		{
			m_ExplodeSprites[i].setPosition(x, y);
		}
		m_positionSet = true;
	}
	
}