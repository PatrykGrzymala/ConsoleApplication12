#include "upgradeImage.h"


upgradeImage::upgradeImage()
{
	if (!backgroundTexture.loadFromFile("Textury/upgradeTexture.png"))
	{
		std::cout << "Unable to open upgradeTexture";
		return;
	}
	background.setTexture(backgroundTexture);

	if (!arrowTexture.loadFromFile("Textury/arrowTexture.png"))
	{
		std::cout << "Unable to open arrowTexture";
		return;
	}
	arrow[0].setTexture(arrowTexture);
	arrow[1].setTexture(arrowTexture);

	maxText.setFont(*Gra::getInstance()->getFont());
	maxText.setCharacterSize(20);
	maxText.setString("MAX");
	maxText.setColor(sf::Color::Black);
	maxText.setStyle(sf::Text::Bold);
}

upgradeImage::~upgradeImage()
{
}

void upgradeImage::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);

	switch (towerLvl)
	{
	case 0: {target.draw(arrow[0]); } break;
	case 1: {target.draw(arrow[0]); target.draw(arrow[1]); } break;
	case 2: {target.draw(maxText); } break;
	}
}

void upgradeImage::setPosition(const sf::Vector2f position)
{
	background.setPosition(position);

	sf::Vector2f arrow1Pos = getMiddlePosition(background.getGlobalBounds(), arrow[0].getGlobalBounds());
	arrow[0].setPosition(arrow1Pos);

	sf::Vector2f arrow2Pos = getMiddlePosition(background.getGlobalBounds(), arrow[1].getGlobalBounds());
	arrow2Pos.y += arrow[0].getGlobalBounds().height / 2;
	arrow[1].setPosition(arrow2Pos);

	sf::Vector2f textPos = getMiddlePosition(background.getGlobalBounds(), maxText.getGlobalBounds());
	textPos.y -= maxText.getGlobalBounds().height * 1 / 3;
	maxText.setPosition(textPos);
}

sf::Vector2f upgradeImage::getSize()
{
	sf::Vector2f size;
	size.x = background.getGlobalBounds().width;
	size.y = background.getGlobalBounds().height;

	return size;
}

bool upgradeImage::isExtended()
{
	return (towerLvl == tower::maxUpgradeLevel);
}

sf::Vector2f upgradeImage::getPosition()
{
	return background.getPosition();
}

void upgradeImage::makeUnaccesibleBackgr()
{
	background.setColor(sf::Color::Black);
	arrow[0].setColor(sf::Color::Red);
	arrow[1].setColor(sf::Color::Red);
}

void upgradeImage::makeAccesibleBackr()
{
	background.setColor(sf::Color(255, 255, 255));
	arrow[0].setColor(sf::Color(255, 255, 255));
	arrow[1].setColor(sf::Color(255, 255, 255));
}

bool upgradeImage::clicked()
{
	sf::Vector2f mousePos = getMousePos();
	if ((background.getGlobalBounds().contains(mousePos)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (Button::canClick()))
	{
		return true;
	}

	return false;
}

void upgradeImage::upgradeLevel()
{
	towerLvl++;

	switch (towerLvl)
	{
	case 0:
	{
		sf::Vector2f arrow1Pos = getMiddlePosition(background.getGlobalBounds(), arrow[0].getGlobalBounds());
		arrow[0].setPosition(arrow1Pos);
	} break;
	case 1:
	{
		sf::Vector2f arrow1Pos = getMiddlePosition(background.getGlobalBounds(), arrow[0].getGlobalBounds());
		arrow1Pos.y -= arrow[0].getGlobalBounds().height / 2;
		arrow[0].setPosition(arrow1Pos);
	} break;
	}
}