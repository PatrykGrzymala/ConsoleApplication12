#include "Template.h"
#include "workshop.h"
#include "Gra.h"
#include <typeinfo>
#include "MainGra.h"
#include "base.h"


workshop::workshop()
{
	if (!backgroundTexture.loadFromFile("Textury/towerHandler.png"))
	{
		std::cout<<"Unable to open towerTexture, please call to BartekS0ft";
		return;
	}
	background.setSize(sf::Vector2f(1000, 100));
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 900);

	setTexts();
}

workshop::~workshop()
{

}

void workshop::update()
{
	if (busy())
	{
		towerInWorkshop->getWorkshopTemplate()->update();
	}
}

void workshop::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);
	if (busy())
	{
		target.draw(*towerInWorkshop->getWorkshopTemplate());
	}
	else
	{
		target.draw(caption);
	}
}

void workshop::join(std::shared_ptr<tower> tower)
{
	towerInWorkshop = tower;
	towerInWorkshop->getWorkshopTemplate()->join(this);
}

void workshop::leave()
{
	towerInWorkshop.reset();
}

bool workshop::isMouseOn(sf::Vector2f mousePosition)
{
	if (background.getGlobalBounds().contains(mousePosition))
		return true;

	return false;
}

sf::Vector2f workshop::getSize()
{
	return background.getSize();
}

sf::Vector2f workshop::getPosition()
{
	return background.getPosition();
}

bool workshop::busy() const
{
	return bool(towerInWorkshop);
}


void workshop::setTexts()
{
	sf::Font *font = Gra::getInstance()->getFont();

	caption.setFont(*font);
	caption.setString("WORKSHOP");
	caption.setCharacterSize(70);
	caption.setColor(sf::Color(150, 20, 250));
	sf::Vector2f captionPos = getMiddlePosition(background.getGlobalBounds(), caption.getGlobalBounds());
	captionPos.y -= 15.f;
	caption.setPosition(captionPos);
}

