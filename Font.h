#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Font
{
protected:
	sf::Font font;

public:
	Font() {
		if (!font.loadFromFile("OpenSans-Regular.ttf")) { return; }
	}
};
