#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void BeginDraw(); //clear window
	void EndDraw(); //draw window

	void Update();

	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();

	void Draw(sf::Drawable& l_drawable);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreeen;
};

