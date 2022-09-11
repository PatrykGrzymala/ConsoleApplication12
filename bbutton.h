#pragma once
#include "Template.h"
#include "Button.h"
enum Type { SMALL, MEDIUM, LARGE };

class bbutton :public sf::Text
{
	bool isBoosted;
	sf::RectangleShape bbutton1;
	
public:
	
	bbutton(std::string tekst, int size, sf::Font font, sf::Vector2f position, sf::Vector2f sizee);

	~bbutton() {};
	Type size;
	sf::Text text1;
	void increase();
	void decrease();
	bool isMouseOn();
	
	bool isIncreased();
	bool isClickOn(sf::Vector2f mousePosition);

	void setFont(sf::Font &font);
};
