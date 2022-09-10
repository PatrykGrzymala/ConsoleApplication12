#pragma once
//#include "bullet.h"
//#include "animation.h"

class straightBullet //:public bullet
{

	sf::Vector2f destinationPoint;
	sf::Vector2f velocity;

	bool destinationAchieved(sf::Vector2f movement);
	bool targetAchieved;

public:
	straightBullet(std::string textureName, sf::Vector2f vel, sf::Vector2f destination, sf::Vector2f startPos);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void update();
	bool achieved();
};
