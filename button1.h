#pragma once

enum Type { SMALL, MEDIUM, LARGE };

class button1 :public sf::Text
{
	bool isBoosted;

public:
	button1(Type type = MEDIUM, sf::Vector2f position = sf::Vector2f(0.f, 0.f), std::string caption = "Captio");
	~button1() {};
	Type size;

	void increase();
	void decrease();
	bool isMouseOn(sf::Vector2f mousePosition);

	bool isIncreased();
	bool isClickOn(sf::Vector2f mousePosition);
};
