#pragma once
#include "gameCtrl.h"
#include "Button.h"
#include "Font.h"

class ChooseLevel :public gameCtrl, private Font
{
	sf::Sprite easyLevelScreen;
	sf::Sprite mediumLevelScreen;
	sf::Sprite hardLevelScreen;
	sf::Texture textureScreens[3];

	sf::Sprite background;
	sf::Texture tBackground;

	sf::Text text;
	sf::Text textEasy;
	sf::Text textMedium;
	sf::Text textHard;

	button buttonBack;
	std::string fileName;

	void loadTextures();
	void makeSettings();
	void handleButton();
	void handleScreens();

public:
	ChooseLevel();
	~ChooseLevel();
	void update();
	void draw(sf::RenderWindow &window);
};
