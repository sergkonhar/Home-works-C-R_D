#include "GameOver.h"

enum class pauseMenyState
{
	Continue,
	ExitToMain,
	ExitGame,
	None
};

GameOver::GameOver()
{
	m_font.loadFromFile("arial.ttf");
	m_gameOverText.setFont(m_font);
	m_scoreText.setFont(m_font);
	m_controlText.setFont(m_font);

	m_gameOverText.setString("Game Over");
	m_scoreText.setString("");
	m_controlText.setString("Use Enter to return to Main Menu, or Esc to Exit");

	m_gameOverText.setCharacterSize(90);
	m_scoreText.setCharacterSize(50);
	m_controlText.setCharacterSize(50);

	m_gameOverText.setFillColor(sf::Color::White);
	m_scoreText.setFillColor(sf::Color::White);
	m_controlText.setFillColor(sf::Color::White);

	m_gameOverText.setPosition(700, 50);
	m_scoreText.setPosition(700, 150);
	m_controlText.setPosition(500, 250);

	m_backgroundTexture.loadFromFile("GameOver.jpg");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	blendMode = sf::BlendMax;

	m_scoreString = "Your score  ";
	m_score = "";

}

void GameOver::formScores(int scores)
{
	m_score = std::to_string(scores);
	while (m_score.length() < 9) 
	{
		m_score = "0" + m_score;
	}
}

void GameOver::draw(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite, blendMode);
	window.draw(m_gameOverText);
	window.draw(m_scoreText);
	window.draw(m_controlText);
}

pauseMenyState GameOver::processMenu(sf::Event& event, sf::RenderWindow& window, int scores)
{
	while (true)
	{
		formScores(scores);
		m_scoreText.setString(m_scoreString + m_score);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}

				else if (event.key.code == sf::Keyboard::Key::Enter)
				{
					return pauseMenyState::ExitToMain;
				}
			}

		}
		window.clear();
		draw(window);
		window.display();
	}
}