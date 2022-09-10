#include "textureCache.h"

textureCache::textureCache()
{
	loadTowerTextures();

	loadTowerBullets();
	loadAnimations();
	loadTextures();
	loadPadlock();
	loadMonsterEffects();
}

textureCache::~textureCache()
{
}

void textureCache::loadTowerTextures()
{
	if (!towerTextures["arcaneTower"].loadFromFile("Textury/Towers/arcaneTower/arcaneTower.png"))
	{
		std::cout<<"Unable to open tower texture";
		return;
	}

	if (!towerTextures["archerTower"].loadFromFile("Textury/Towers/archerTower/archerTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["cannonTower"].loadFromFile("Textury/Towers/cannonTower/cannonTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["darkTower"].loadFromFile("Textury/Towers/darkTower/darkTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["magmaTower"].loadFromFile("Textury/Towers/magmaTower/magmaTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["antennaTower"].loadFromFile("Textury/Towers/antennaTower/antennaTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["electricTower"].loadFromFile("Textury/Towers/electricTower/electricTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["poisonTower"].loadFromFile("Textury/Towers/poisonTower/poisonTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["crossbowTower"].loadFromFile("Textury/Towers/crossbowTower/crossbowTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["lightingTower"].loadFromFile("Textury/Towers/lightingTower/lightingTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["iceTower"].loadFromFile("Textury/Towers/iceTower/iceTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["deathTower"].loadFromFile("Textury/Towers/deathTower/deathTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["laserTower"].loadFromFile("Textury/Towers/laserTower/laserTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerTextures["signalTower"].loadFromFile("Textury/Towers/signalTower/signalTower.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
}

void textureCache::loadTowerBullets()
{
	if (!towerBullets["arcaneTowerBullet"].loadFromFile("Textury/Towers/arcaneTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["archerTowerBullet"].loadFromFile("Textury/Towers/archerTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["cannonTowerBullet"].loadFromFile("Textury/Towers/cannonTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["darkTowerBullet"].loadFromFile("Textury/Towers/darkTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["magmaTowerBullet"].loadFromFile("Textury/Towers/magmaTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["poisonTowerBullet"].loadFromFile("Textury/Towers/poisonTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["crossbowTowerBullet"].loadFromFile("Textury/Towers/crossbowTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["thunder"].loadFromFile("Textury/Towers/lightingTower/thunder.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["iceTowerBullet"].loadFromFile("Textury/Towers/iceTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!towerBullets["deathTowerBullet"].loadFromFile("Textury/Towers/deathTower/bullet.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
}

void textureCache::loadAnimations()
{
	if (!animations["smallExplosion"].loadFromFile("Textury/Towers/cannonTower/explosion.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!animations["magmaExplosion"].loadFromFile("Textury/Towers/magmaTower/explosion.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!animations["bundleEnergy"].loadFromFile("Textury/Towers/electricTower/energy.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
}

void textureCache::loadPadlock()
{
	if (!padlock.loadFromFile("Textury/padlock.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
}

void textureCache::loadTextures()
{
	if (!textures["magma"].loadFromFile("Textury/Towers/magmaTower/magma.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!textures["crossbow"].loadFromFile("Textury/Towers/crossbowTower/crossbow.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!textures["laser"].loadFromFile("Textury/Towers/laserTower/laser.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}

	if (!textures["arrowDir"].loadFromFile("Textury/Towers/laserTower/arrow.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
}

void textureCache::loadMonsterEffects()
{
	if (!monsterEffects["poison"].loadFromFile("Textury/Towers/effects/poison.png"))
	{
		std::cout << "Unable to open tower texture";
		return;
	}
	print("pobieramy poisona");
}


sf::Texture * textureCache::getPadlock()
{
	return &padlock;
}

sf::Texture *textureCache::getTowerTexture(std::string textureName)
{
	return &towerTextures[textureName];
}

sf::Texture * textureCache::getTowerBullet(std::string bulletName)
{
	return &towerBullets[bulletName];
}

sf::Texture * textureCache::getAnimation(std::string bulletExploName)
{
	return &animations[bulletExploName];
}

sf::Texture * textureCache::getTexture(std::string textureName)
{
	return &textures[textureName];
}

sf::Texture * textureCache::getMonsterEffectTexture(std::string effectName)
{
	return &monsterEffects[effectName];
}