#pragma once
#include "gameCtrl.h"
#include "Font.h"
#include "menuParticleSystem.h"
#include "Button.h"
#include <thread>

#define MENU

class Menu :public gameCtrl, private Font
{
	std::thread loadingThread;
	sf::Text title;
	menuParticleSystem particleSystem;

	std::vector <Button> buttons;
	void handleButtons();

	int currentButton;
	void followFunc(int index);

public:
	Menu();
	~Menu();

	void update();
	void draw(sf::RenderWindow &window);
};
