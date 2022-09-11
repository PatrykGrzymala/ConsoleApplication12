#pragma once
#include "Template.h"
class bullet
{
public:
	bullet(sf::Vector2f size){

	}
	~bullet();
	sf::Vector2f newPos;
	sf::RenderWindow& window;
	int speed;

	void fire(int speed)
	{
		bullets.move(speed, 0);
	}

	int getRight()
	{
		return bullets.getPosition().x + bullets.getSize().x;
	}

	int getLeft()
	{
		return bullets.getPosition().x;
	}

	int getTop()
	{
		return bullets.getPosition().y;
	}

	int getBottom()
	{
		return bullets.getPosition().y + bullets.getSize().y;
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(bullets);
	}

	void setPos(sf::Vector2f newPos)
	{
		bullets.setPosition(newPos);
	}

	void rotate() {

	}

	void update() {

	}

	sf::RectangleShape bullets;
	std::string bulletTextureName;
};