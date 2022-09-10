#pragma once
#include "gameCtrl.h"
#include "map.h"
#include "path.h"
#include "wave.h"
#include <queue>
#include "textureCache.h"
#include "workshop.h"
#include "wallet.h"
#include "pause.h"
#include "levelInterlude.h"
#include "gameLoader.h"

class MainGra :public gameCtrl
{
	friend class towerManagament;
	friend class upgradeImage;

	static MainGra* instance;

	map Map;
	std::vector <wave> waves;
	std::vector <wave*> _waves;
	void loadLevel(const std::string fileName);

	std::unique_ptr<towerManagament> shop;
	std::unique_ptr<levelInterlude> lvlInterlude;
	workshop towerHandler;

	wallet money;
	int level;
	sf::Text skipLevelText;
	sf::Text levelCounter;

	pause pauser;
	gameLoader loader;
	sf::RenderWindow  & wnd;

	std::shared_ptr<tower> _base;
	hpBar gameHPbar;
	sf::Music music;
	float musicVolume;
	std::string levelName;
	void prepareToNewWave();
	int lifes;
	const int maxLifes = 100;
	int wavesDied;
	int waveNumber;

public:
	MainGra(const std::string fileName);
	~MainGra();
	void update();
	void updateGame();
	void draw(sf::RenderWindow &window);
	map *getMap();
	path levelPath;
	textureCache textures;
	wallet *getWallet();
	int *getLevel();
	std::string getLevelName();
	std::vector<wave*> & getWaves();
	int getLifes();
	void subtractLife(int lifeAmount);

	int *getHP();
	sf::Music *getMusic();

	static MainGra* getInstance();
};
