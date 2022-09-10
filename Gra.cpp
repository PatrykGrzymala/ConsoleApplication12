#include "Template.h"
#include "Gra.h"
#include "Menu.h"

Gra *Gra::instance = nullptr;

Gra::Gra()
	:window(sf::VideoMode(WIDTH, HEIGHT), "Gra Tower Defensowa")
{
	if (instance == nullptr)
	{
		instance = this;
	}

	if (!music.openFromFile("Music/mainMenuTheme.wav"))
	{
		std::cout<<"Nie mozna otworzyc mainMenuTheme.wav, brak pliku";
		exit();
	}

	if (!icon.loadFromFile("Textury/icon.png"))
	{
		std::cout << "Nie mozna otworzyc icon.png, brak pliku";
		exit();
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	music.play();
	music.setLoop(true);

	gameController = std::make_unique<Menu>();


	accumulator = sf::Time::Zero;
	clock.restart();

	timer = sf::Time::Zero;
	clocker.restart();

	loadFont();
}

Gra::~Gra()
{
	instance = nullptr;
}

void Gra::run()
{
	sf::Time deltaTime = sf::Time::Zero;
	sf::Clock deltaClock;

	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();

		}

		deltaTime = deltaClock.restart();
		accumulator += clock.restart();

		if (accumulator > frameTime)
		{
			timer = clocker.restart();
			gameController->update();
			Button::update();


			accumulator -= frameTime;
		}
		fpser.countTime(deltaTime);

		window.clear(sf::Color::Black);
		gameController->draw(window);
		window.draw(fpser);
		window.display();

		++fpser;

	}
}

Gra * Gra::getInstance()
{
	return instance;
}

sf::RenderWindow & Gra::getWindow()
{
	return window;
}

sf::Font  *Gra::getFont()
{
	return &font;
}

sf::Time Gra::getTimer()
{
	return timer;
}


void Gra::setController(std::unique_ptr <gameCtrl> newController)
{
	gameController = std::move(newController);
}

void Gra::exit()
{
	window.close();
}

sf::Music * Gra::getMusic()
{
	return &music;
}

void Gra::hurryUpTime()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		for (int i = 0; i < 3; ++i)
		{
			timer += timer;
		}
	}
}

void Gra::loadFont()
{
	if (!font.loadFromFile("Fonty/Lato-Medium.ttf"))
	{
		std::cout <<"Unable to load Anorexia.ttf";
	}

}