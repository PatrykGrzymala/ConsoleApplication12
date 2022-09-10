#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Gra.h"

class Basehp :public sf::Drawable
{
	int hp;
	sf::Text hpText;
	sf::Sprite heart;
	sf::Texture heartTexture;
	sf::Font font;

public:
	Basehp();
	~Basehp();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	int getHP();
	bool isAfford(int amount);
	void pay(int amount);
	void setPosition(const sf::Vector2f position);
	void deposit(int amount);

	sf::Vector2f getSize();
};
