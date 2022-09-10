#pragma once
#include "gameCtrl.h"
#include "Button.h"

class pause :public sf::Drawable
{
	sf::Sprite background;
	sf::Texture texture;
	sf::Sprite bell;
	sf::Texture bellT;
	bool musicOn;

	Button buttons[4];
	bool isPause;
	void setButtons();
	void followFunc(int index);

public:
	pause();
	~pause();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void update();
	void turnOn();
	bool isOn();
};
