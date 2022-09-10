#include "Template.h"
#include "Button.h"

bool Button::isButtonActive = false;
std::map<sf::Keyboard::Key, bool> Button::buttons = std::map<sf::Keyboard::Key, bool>();

Button::Button()
{
	isButtonActive = false;
}

Button::~Button()
{
}

void Button::update()
{
	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (!isButtonActive))
	{
		isButtonActive = true;
	}
	else if ((!sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (isButtonActive))
	{
		isButtonActive = false;
	}

	std::map<sf::Keyboard::Key, bool>::iterator itr = buttons.begin(), end = buttons.end();

	for (itr; itr != end; itr++)
	{
		if (sf::Keyboard::isKeyPressed(itr->first) && (!itr->second))
		{
			itr->second = true;
		}
		else if ((!sf::Keyboard::isKeyPressed(itr->first)) && (itr->second))
		{
			itr->second = false;
		}
	}
}

bool Button::canClick()
{
	return !isButtonActive;
}

bool Button::canClickKey(sf::Keyboard::Key key)
{

	std::map<sf::Keyboard::Key, bool>::iterator itr = buttons.find(key);

	if (itr == buttons.end())
	{
		buttons[key] = true;
		return true;
	}

	if (itr->second)
		return false;
	else
	{
		itr->second = true;
		return true;
	}
}