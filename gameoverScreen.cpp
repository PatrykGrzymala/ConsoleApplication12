#include "gameoverScreen.h"


gameoverScreen::gameoverScreen()
{
	if (!backgroundT.loadFromFile("Textury/GOBackground.png"))
	{
		std::cout<<"Unable to open gameOverBackground.png";
		return;
	}
	background.setTexture(backgroundT);

	if (!soundBuffer.loadFromFile("Music/loseGameSound.wav"))
	{
		std::cout<<"Unable to open loseGame.wav";
		return;
	}
	sound.setBuffer(soundBuffer);
	sound.setVolume(70);
	sound.play();

	//backButton.setFont(*Gra::getInstance()->getFont());
	//backButton.setCharacterSize(30);
	//backButton.setString("Back");
	//backButton.setFillColor(sf::Color::Red);
	//backButton.setPosition(getMidlePosition(sf::Vector2f(WIDTH / 2, HEIGHT * 4 / 5), backButton.getGlobalBounds()));
}

gameoverScreen::~gameoverScreen()
{
}

void gameoverScreen::update()
{
	particleSystem.update();

	sf::Vector2f mousePos = getMousePos();

	if (backButton.getGlobalBounds().contains(mousePos))
	{
		//if (!backButton.isIncreased())
		//{
		//	backButton.increase();
		//}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Gra::getInstance()->setController(std::make_unique<Menu>());
			return;
		}
	}
	//else if (!backButton.getGlobalBounds().contains(mousePos))
	//{
	//	if (backButton.isIncreased())
	//	{
	//		backButton.decrease();
	//	}
	//}
}

void gameoverScreen::draw(sf::RenderWindow & window)
{
	window.draw(background);
	window.draw(backButton);
	window.draw(particleSystem);
}