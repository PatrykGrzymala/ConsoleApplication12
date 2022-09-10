#define NOMINMAX
#include "map.h"


/*towers
#include "arcaneTower.h"
#include "archerTower.h"
#include "cannonTower.h"
#include "darkTower.h"
#include "magmaTower.h"
*/
map::map()
{

}

map::~map()
{

}

void map::loadMap(const std::string fileName)
{
	if (!texture.loadFromFile("Textury/" + fileName))
	{
		std::cout<<"Unable to open fileName to load map";
		return;
	}

	background.setTexture(texture);
}

void map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background);
	size_t towerCircleIt;
	bool drawLast = false;

	for (size_t i = 0; i < towers.size(); ++i)
	{
		if (towers[i]->isActive())
		{
			towerCircleIt = i;
			drawLast = true;
			continue;
		}

		target.draw(*towers[i]);
	}

	if (drawLast)
		target.draw(*towers[int(towerCircleIt)]);
}

void map::update()
{
}

bool map::canTowerBuild(std::shared_ptr<tower> &activeTower)
{
	const int vertexes = 4;
	sf::Vector2f towerVertexes[vertexes];

	towerVertexes[0] = activeTower->getPosition();
	towerVertexes[1].x = activeTower->getPosition().x + activeTower->getSize().x;
	towerVertexes[1].y = activeTower->getPosition().y;
	towerVertexes[2].x = activeTower->getPosition().x;
	towerVertexes[2].y = activeTower->getPosition().y + activeTower->getSize().y;
	towerVertexes[3].x = activeTower->getPosition().x + activeTower->getSize().x;
	towerVertexes[3].y = activeTower->getPosition().y + activeTower->getSize().y;



	for (int i = 0; i < vertexes; ++i)
	{
		if (!background.getGlobalBounds().contains(towerVertexes[i]))
		{
			return false;
		}
	}

	for (size_t i = 0; i < unBuildable.size(); ++i)
	{
		if (activeTower->getGlobalBounds().intersects(unBuildable[i]))
		{
			return false;
		}
	}

	for (size_t i = 0; i < towers.size(); ++i)
	{
		if (activeTower->getGlobalBounds().intersects(towers[i]->getGlobalBounds()))
		{
			return false;
		}
	}

	return true;
}

void map::buildTower(std::shared_ptr<tower> &activeTower)
{
	std::shared_ptr <tower> newTower = activeTower->getClassObject();
	newTower->setPosition(activeTower->getPosition());
	newTower->activateHUD();
	newTower->build();
	towers.push_back(newTower);
}

void map::sellTower(tower * sellingTower)
{
	for (size_t i = 0; i < towers.size(); ++i)
	{
		if (towers[i].get() == sellingTower)
			towers.erase(towers.begin() + i);
	}
}

sf::FloatRect map::getBackgroundBounds()
{
	return background.getGlobalBounds();
}
