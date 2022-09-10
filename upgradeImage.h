#pragma once
#define NOMINMAX
#include "Template.h"
#include "Gra.h"
#include "MainGra.h"
#include "tower.h"


class upgradeImage :public sf::Drawable
{
	sf::Sprite background;
	sf::Texture backgroundTexture;

	sf::Sprite arrow[2];
	sf::Texture arrowTexture;

	sf::Text maxText;
	int towerLvl;

	bool isExtended();

public:
	upgradeImage();
	~upgradeImage();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void setPosition(const sf::Vector2f position);
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	void makeUnaccesibleBackgr();
	void makeAccesibleBackr();
	bool clicked();
	void upgradeLevel();
};
