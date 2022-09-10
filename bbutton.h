#pragma once
#include "Template.h"

enum Type { SMALL, MEDIUM, LARGE };

class bbutton :public sf::Text
{
	bool isBoosted;

public:
	bbutton(Type type = MEDIUM, sf::Vector2f position = sf::Vector2f(0.f, 0.f), std::string caption = "Captio");
	~bbutton() {};
	Type size;

	void increase();
	void decrease();
	bool isMouseOn(sf::Vector2f mousePosition);

	bool isIncreased();
	bool isClickOn(sf::Vector2f mousePosition);
};
