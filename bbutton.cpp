#include "bbutton.h"
bbutton::bbutton(std::string tekst, int size, sf::Font font, sf::Vector2f position, sf::Vector2f sizee)
{
text1.setFont(font);
text1.setString(tekst);
text1.setCharacterSize(size);
bbutton1.setPosition(position);
bbutton1.setSize(sizee);
}

bbutton::~bbutton()
{

}
//void bbutton::increase()
//{

//}

void bbutton::setFont(sf::Font &font)
{
	text1.setFont(font);

}
//void bbutton::decrease()
//{

//}

//bool bbutton::isMouseOn(sf::Vector2f cos)
//{


//bool bbutton::isIncreased()
//{

//}

bool bbutton::isClickOn(sf::Vector2f cos)
{
	sf::Vector2f getMousePos();
	float mouseX = cos.x;
	float mouseY = cos.y;

	float btnPosX = bbutton1.getPosition().x;
	float btnPosY = bbutton1.getPosition().y;

	float btnxPosWidth = bbutton1.getPosition().x + bbutton1.getLocalBounds().width;
	float btnxPosHeight = bbutton1.getPosition().y + bbutton1.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnxPosHeight && mouseY > btnPosY && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		return true;
	}
	return false;
	
}
