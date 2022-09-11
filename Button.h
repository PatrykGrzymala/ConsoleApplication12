#pragma once

class Button
{
	static bool isButtonActive;
	static std::map<sf::Keyboard::Key, bool> buttons;
	int INt;
	
public:
	Button();
	~Button();
	static void update();
	static bool canClick();

	static bool canClickKey(sf::Keyboard::Key key);
};