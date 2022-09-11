#pragma once
#include "Template.h"
#include "Window.h"
class bullet : public sf::Drawable, attackTower
{
public:
	bullet(sf::Vector2f size, attackTower* ownr);
	~bullet();
	sf::Vector2f newPos;
	static int speed;
	sf::Vector2f velocity;
	int dmg;
	attackTower *owner;

	sf::Time timeExist;
	static sf::Time timer;


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

	void draw(sf::RenderWindow& target)
	{
		target.draw(bullets);
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