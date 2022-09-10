#include "template.h"
#include "levelInterlude.h"
#include "Gra.h"
#include "MainGra.h"

levelInterlude::levelInterlude(int currentlevel)
{
	setFont(*Gra::getInstance()->getFont());
	setCharacterSize(200);
	setColor(sf::Color(90, 90, 140));
	setString("Level " + intToString(currentlevel));
	sf::FloatRect backgroundRect = MainGra::getInstance()->getMap()->getBackgroundBounds();
	setPosition(getMiddlePosition(backgroundRect, getGlobalBounds()));

	timer = sf::Time::Zero;
	skip = false;
}

levelInterlude::~levelInterlude()
{
}

void levelInterlude::update()
{
	timer += Gra::getInstance()->getTimer();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		skip = true;
	}
}

bool levelInterlude::skipped()
{
	if ((timer >= period) || (skip))
		return true;

	return false;
}