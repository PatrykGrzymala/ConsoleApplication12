#pragma once
#include "Template.h"
#include "gameCtrl.h"
#include "Button.h"
#include "fpsCounter.h"
#define mainLoop

class Gra
{
	static Gra *instance;

	sf::RenderWindow window;
	sf::Event evnt;
	sf::Font font;
	sf::Image icon;

	std::unique_ptr <gameCtrl> gameController;

	sf::Time accumulator;
	const sf::Time frameTime = sf::seconds(1.f / 120.f);
	sf::Clock clock;

	sf::Time timer;
	sf::Clock clocker;

	fpsCounter fpser;
	sf::Music music;
	void loadFont();


public:
	Gra();
	~Gra();

	void run();

	static Gra *getInstance();
	sf::RenderWindow & getWindow();
	sf::Font *getFont();
	sf::Time getTimer();
	void setController(std::unique_ptr <gameCtrl> newController);
	void exit();
	sf::Music * getMusic();
	void hurryUpTime();
};
