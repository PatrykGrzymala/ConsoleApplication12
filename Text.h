#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
/*
class Text : public sf::Drawable, public sf::Transformable
{
public:
	Text();
	~Text();
	sf::Font font;
	//bool loadfont(const std::string& font_file);
	const std::string& font_file = "OpenSans-Regular.ttf";
	sf::String text;
	bool loadtext(std::string string);
	//void draw(sf::RenderTarget& target);
};*/

#pragma once


class fpsCounter :public sf::Drawable
{
	sf::Time timer;
	const sf::Time second = sf::seconds(1.f);
	sf::Text fpsText;
	sf::Text ilosc;
	sf::Font font;

public:
	fpsCounter();
	~fpsCounter();

	int hp = 100;
	int fps;

	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void countTime(sf::Time &gameTimer);

	fpsCounter & operator++();
};