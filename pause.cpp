#include "Template.h"
#include "pause.h"
#include "Gra.h"
#include "MainGra.h"
#include "Menu.h"



pause::pause()
{
	if (!texture.loadFromFile("Textury/pauseTexture.png"))
	{
		std::cout << "Unable to open pauseTexture, please call to BartekS0ft";
		return;
	}
	background.setTexture(texture);

	if (!bellT.loadFromFile("Textury/bell.png"))
	{
		std::cout << "Unable to open bellTexture, please call to BartekS0ft";
		return;
	}
	bell.setTexture(bellT);

	bell.setTextureRect(sf::IntRect(0, 0, bellT.getSize().x / 2, bellT.getSize().y));

	sf::Vector2f backgroundPosition = getMiddlePosition(sf::FloatRect(0.f, 0.f, WIDTH, HEIGHT), background.getGlobalBounds());
	background.setPosition(backgroundPosition);

	sf::Vector2f bellPosition(background.getPosition().x + bell.getGlobalBounds().width * 1.3f, background.getPosition().y + background.getGlobalBounds().height - bell.getGlobalBounds().height * 2.5f);
	bell.setPosition(bellPosition);

	isPause = false;
	musicOn = true;
	setButtons();

}

pause::~pause()
{

}

void pause::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);

	for (int i = 0; i < 4; ++i)
	{
		target.draw(buttons[i]);
	}

	target.draw(bell);
}


void pause::update()
{
	for (int i = 0; i < 4; ++i)
	{
		if (buttons[i].isClickOn(getMousePos()))
		{
			followFunc(i + 1);
		}
	}

	if ((Button::canClick()) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (bell.getGlobalBounds().contains(getMousePos())))
	{
		if (musicOn)
		{
			MainGra::getInstance()->getMusic()->setVolume(0);
			bell.setTextureRect(sf::IntRect(bellT.getSize().x / 2, 0, bellT.getSize().x / 2, bellT.getSize().y));
			musicOn = false;
		}
		else
		{
			MainGra::getInstance()->getMusic()->setVolume(30);
			bell.setTextureRect(sf::IntRect(0, 0, bellT.getSize().x / 2, bellT.getSize().y));
			musicOn = true;
		}
	}
}

void pause::turnOn()
{
	isPause = true;
}

bool pause::isOn()
{
	return isPause;
}

void pause::setButtons()
{
	sf::Font *font = Gra::getInstance()->getFont();

	buttons[0].setString("Resume");
	buttons[1].setString("Restart");
	buttons[2].setString("Menu");
	buttons[3].setString("Exit game");

	float axisXPos = background.getPosition().x + 0.5f * background.getGlobalBounds().width;
	float axisYPos;
	float x, y;

	for (int i = 0; i < 4; i++)
	{
		buttons[i].setFont(*font);
		buttons[i].setCharacterSize(30);
		buttons[i].setColor(sf::Color(10 + 10 * i, 10 + 20 * i, 50 + i));

		x = axisXPos;
		x -= buttons[i].getGlobalBounds().width / 2;
		axisYPos = background.getPosition().y + background.getGlobalBounds().height * (i + 1) / 5;
		y = axisYPos - buttons[i].getGlobalBounds().height / 2;

		buttons[i].setPosition(x, y);

	}


}

void pause::followFunc(int index)
{
	switch (index)
	{
	case 1: isPause = false; break;
	case 2: {std::string fileName = MainGra::getInstance()->getLevelName();
		Gra::getInstance()->setController(std::make_unique<MainGra>(fileName)); } break;
	case 3: Gra::getInstance()->setController(std::make_unique<Menu>()); break;
	case 4:  Gra::getInstance()->exit(); break;

	}
}