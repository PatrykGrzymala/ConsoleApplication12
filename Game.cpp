#include "Game.h"



Game::Game() : m_window("Gra Tower Defense", sf::Vector2u(1280, 640))
{	

	m_tilemap.load("tileset.png", sf::Vector2u(32, 32),*mapa1, 40, 20);
	m_mushroomTexture.loadFromFile("obrazek.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(100, 300); //pixeli na sek
	m_isDone = false;
}

Game::~Game() 
{

}

void Game::Run(Game& t)
{
	timesinceupdate = sf::Time::Zero; 
	while (!t.GetWindow()->IsDone())
	{
		//Game loop
		HandleInput();
		timesinceupdate += clock.restart();
		while (timesinceupdate > TimePerFrame)
		{
			timesinceupdate -= TimePerFrame;
			HandleInput();
			Update();
		}

		Render();
		//RestartClock();
	}
}

void Game::Update() 
{
	m_window.Update();
	MoveMushroom();
}

void Game::MoveMushroom() 
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();

	if ((m_mushroom.getPosition().x >l_windSize.x - l_textSize.x&&m_increment.x > 0) ||
		(m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
		m_increment.x = -m_increment.x;
	}
	if ((m_mushroom.getPosition().y >l_windSize.y - l_textSize.y&&m_increment.y > 0) ||
		(m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
		m_increment.y = -m_increment.y;
	}
	float fElapsed = TimePerFrame.asSeconds();
	m_mushroom.setPosition(
		m_mushroom.getPosition().x + (m_increment.x * fElapsed),
		m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_tilemap);
	m_window.Draw(m_mushroom);
	m_window.EndDraw();
}

Window * Game::GetWindow()
{
	return &m_window;
}

//sf::Time Game::GetElapsed() { return m_elapsed;  }
//void Game::RestartClock() { m_elapsed += m_clock.restart(); }

void Game::HandleInput() 
{

}

