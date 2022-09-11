#include "bbutton.h"
bbutton::bbutton(std::string tekst, int size, sf::Font font, sf::Vector2f position, sf::Vector2f sizee)
{
text1.setFont(font);
text1.setString(tekst);
text1.setCharacterSize(size);
bbutton1.setPosition(position);
bbutton1.setSize(sizee);
}
void bbutton::increase()
{

}

void bbutton::setFont(sf::Font &font)
{
	text1.setFont(font);

}
void bbutton::decrease()
{

}

bool bbutton::isMouseOn()
{
	
		float mouseX = getMousePos().x;
		float mouseY = getMousePos().y;

		float btnPosX = bbutton1.getPosition().x;
		float btnPosY = bbutton1.getPosition().y;

		float btnxPosWidth = bbutton1.getPosition().x + bbutton1.getLocalBounds().width;
		float btnxPosHeight = bbutton1.getPosition().y + bbutton1.getLocalBounds().height;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnxPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
}

bool bbutton::isIncreased()
{

}

bool bbutton::isClickOn(sf::Vector2f mousePosition)
{

}
