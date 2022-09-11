#include "bbutton.h"
bbutton::bbutton(std::string tekst, int size, sf::Font font, sf::Vector2f position, sf::Vector2f sizee)
{
bbutton1.setFont(font);
bbutton1.setString(tekst);
bbutton1.setCharacterSize(size);
bbutton1.setPosition(position);
bbutton1.setSize(sizee);
}
void increase()
{

}

void setFont(sf::Font &font)
{
	tekst.setFont(font);
	tekst

}
void decrease()
{

}

float isMouseOn()
{
	
		float mouseX = getMousePos().x;
		float mouseY = getMousePos().y;

		float btnPosX = bbutton1.getPosition().x;
		float btnPosY = bbutton1.getPosition().y;

		float btnxPosWidt = bbutton1.getPosition().x + bbutton1.getLocalBounds().width;
	
}

bool isIncreased()
{

}

bool isClickOn(sf::Vector2f mousePosition)
{

}
