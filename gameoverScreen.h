#pragma once
#include "gameCtrl.h"
#include "Button.h"
#include "Menu.h"
#include "Template.h"
#include "Gra.h"


class gameoverScreen :public gameCtrl
{
	sf::Sprite background;
	sf::Texture backgroundT;
	Button backButton;
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;

public:
	gameoverScreen();
	~gameoverScreen();
	void update() override;
	void draw(sf::RenderWindow &window);
};