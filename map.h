#pragma once
#include "Template.h"
#include "MainGra.h"
#include "towerManagement.h"
#include "tower.h"
class map :public sf::Drawable, public sf::Transformable
{
	friend class MainGra;
	friend class towerManagament;
	friend class tower;


public:
	map();
	~map();
	std::vector <std::shared_ptr<tower>> towers;
	void loadMap(const std::string fileName);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void update();
	bool canTowerBuild(std::shared_ptr<tower> &activeTower);

	std::vector <sf::FloatRect> unBuildable;
	void buildTower(std::shared_ptr<tower> &activeTower);
	void sellTower(tower* sellingTower);

	sf::FloatRect getBackgroundBounds();
	sf::Texture texture;
	sf::Sprite background;
};
