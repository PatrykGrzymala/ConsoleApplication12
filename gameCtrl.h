#pragma once
#include "Template.h"

class gameCtrl
{
public:
	virtual ~gameCtrl() {};
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
};
