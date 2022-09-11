#include "Window.h"
#include "TileMap.h"
#include <stdlib.h>

class Game : public TileMap
{
public:
	Game();
	~Game();

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
private:
	void MoveMushroom();
	Window m_window;
	TileMap m_tilemap;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f); //60fps
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;
	bool m_isDone;
};

