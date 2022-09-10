#pragma once
#include <queue>
#include "Template.h"
#include "MainGra.h"
class path
{
	friend class mainGame;
	friend class monster;

	std::vector <sf::Vector2f> wayPoints;


	void makeUnBuildablePath();



public:
	std::queue <sf::Vector2f> waypoints;
	path();
	~path();

	static const float width;
};