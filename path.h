#pragma once
#include <queue>
#include "Template.h"
#include "MainGra.h"
class path
{
	friend class MainGra;
	friend class monster;

	



public:
	std::queue <sf::Vector2f> waypoints;
	path();
	~path();
	void makeUnBuildablePath();
	static const float width;
	std::vector <sf::Vector2f> wayPoints;
};