/*
#include "Window.h"
#include "TileMap.h"
#include "Text.h"
#include "Template.h"
#include "Button.h"

#include <stdlib.h>
#include <iostream>

class Game : public TileMap, public fpsCounter
{
	static Game *instance;
public:
	Game();
	~Game();

	static Game *getInstance();

	void Run(Game& t);
	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow();
	//sf::Time GetElapsed();
	//void RestartClock();
	//sf::Time m_elapsed;
	sf::Clock clock;
	sf::Clock m_clock;
	sf::Time timesinceupdate;

	fpsCounter fpser;
	fpsCounter ilosc;

private:
	void MoveMushroom(fpsCounter& counter);
	Window m_window;
	TileMap m_tilemap;
	fpsCounter m_counter;
	
	int speed_x = 500;
	int	speed_y = 500;
	int hp_value;
	
	
	sf::String m_tekst;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f); //60fps
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Text xd;
	sf::Vector2i m_increment;
	sf::Vector2i m_start;
	sf::Vector2f m_scale;
	sf::Vector2i m_prev;
	bool m_isDone;
};

*/
