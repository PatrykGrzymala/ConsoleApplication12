#pragma once
#include "Window.h"

class levelInterlude :public sf::Text
{
	const sf::Time period = sf::seconds(3.f);
	sf::Time timer;
	bool skip;
public:
	levelInterlude(int currentlevel);
	~levelInterlude();
	void update();
	bool skipped();
}; 
