#include "Basehp.h"

std::string intToString(int number)
{
	std::stringstream ss;

	ss << number;
	return ss.str();
}
Basehp::Basehp()
{
	if (!heartTexture.loadFromFile("heart.png"))
	{
		std::cout<<"nie ma hp";
		return;
	}
	heart.setTexture(heartTexture);

	hp = 100;
	font.loadFromFile("OpenSans-Regular.ttf");
	hpText.setFont(font);
	hpText.setString(intToString(hp));
	hpText.setCharacterSize(30);
	hpText.setFillColor(sf::Color(30, 40, 30));
	sf::Vector2f textPos;
	textPos.x = heart.getPosition().x + heart.getGlobalBounds().width * 3 / 2;
	textPos.y = heart.getPosition().y + heart.getGlobalBounds().height / 2 - hpText.getGlobalBounds().height / 2;
	hpText.setPosition(textPos);

}


Basehp::~Basehp()
{
}

void Basehp::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(heart);
	target.draw(hpText);
}

int Basehp::getHP()
{
	return hp;
}

bool Basehp::isAfford(int amount)
{
	if (this->hp >= amount)
		return true;

	return false;
}

void Basehp::pay(int amount)
{
	hp -= amount;

	hpText.setString(intToString(hp));
}

void Basehp::setPosition(const sf::Vector2f position)
{
	heart.setPosition(position);

	sf::Vector2f textPos;
	textPos.x = position.x + heart.getGlobalBounds().width * 3 / 2;
	textPos.y = position.y + heart.getGlobalBounds().height / 2 - hpText.getGlobalBounds().height * 2 / 3;

	hpText.setPosition(textPos);
}

void Basehp::deposit(int amount)
{
	hp += amount;
	hpText.setString(intToString(hp));
}

sf::Vector2f Basehp::getSize()
{
	sf::Vector2f size;
	size.x = (hpText.getPosition().x + hpText.getGlobalBounds().width) - heart.getPosition().x;

	if (hpText.getGlobalBounds().height <= heart.getGlobalBounds().height)
		size.y = heart.getGlobalBounds().height;
	else size.y = hpText.getGlobalBounds().height;

	return size;
}