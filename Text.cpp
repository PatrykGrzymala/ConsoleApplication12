#include "Text.h"

//bool Text::loadfont(const std::string& font_file)
//{
//	if (!font.loadFromFile(font_file))
//	{
//		std::cout << "Nie dziala czcionka!";
//		return false;
//	}
//	return true;
//}

//bool Text::loadtext(sf::Text& text, sf::Font& font)
//{
	//if(!font.loadFromFile("OpenSans-Regular.ttf"))
	//	return false;
//	text.setFont(font); // font is a sf::Font

	// set the string to display
//	text.setString("100 HP");

	// set the character size
//	text.setCharacterSize(24); // in pixels, not points!

	// set the color
//	text.setFillColor(sf::Color::Red);

	// set the text style
//	text.setStyle(sf::Text::Bold);
//	text.setPosition(100, 100);

//}
/*bool Text::loadtext(std::string tekst)
{
	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))  //"OpenSans-Regular.ttf"
			return false;
		text.setFont(font);
	
	int number = 1000;
	std::ostringstream oss;
	oss << number;

	
	text.setFont(font);
	text.setString(tekst);
	text.setFillColor(sf::Color::Red);
	text.setPosition(400, 300);

	return true;
}*/

std::string intToStringer(int number)
{
	std::stringstream ss;

	ss << number;
	return ss.str();
}


fpsCounter::fpsCounter()
{
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		std::cout << "nie udalo sie zaladowac czcionki";
	}
	hp = 100;
	fps = 0;
	timer = sf::Time::Zero;
	
	//if (((int)Game.m_mushroom.getPosition().y / 32) == 17 && ((int)m_mushroom.getPosition().x / 32) == 20)
	//	fpsCounter hp = hp - 3;

	fpsText.setFont(font);
	fpsText.setCharacterSize(30);
	fpsText.setPosition(0, 600);
	fpsText.setFillColor(sf::Color(256, 256, 256));
	fpsText.setString("FPS: ");

	ilosc.setFont(font);
	ilosc.setCharacterSize(30);
	ilosc.setPosition(0, 0);
	ilosc.setFillColor(sf::Color(256, 256, 256));
	ilosc.setString("HP: " + intToStringer(hp));
}

fpsCounter::~fpsCounter()
{
}

void fpsCounter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(fpsText);
	target.draw(ilosc);
}

void fpsCounter::countTime(sf::Time & gameTimer)
{
	timer += gameTimer;

	if (timer >= second)
	{
		fpsText.setString("fps = " + intToStringer(fps));
		fps = 0;
		timer = sf::Time::Zero;
	}
}

fpsCounter & fpsCounter::operator++()
{
	fps++;
	return *this;
}


