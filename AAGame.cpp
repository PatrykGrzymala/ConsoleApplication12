/*
#include "Game.h"
#include "Template.h"

Game *Game::instance = nullptr;

Game::Game() : m_window("Gra Tower Defense", sf::Vector2u(1280, 640))
{	
	if (instance == nullptr)
	{
		instance = this;
	}
	m_start = sf::Vector2i(0, 6);
	m_prev = sf::Vector2i (0, 6*32);
	m_tilemap.load("tileset.png", sf::Vector2u(32, 32),*mapa1, 40, 20);
	m_mushroomTexture.loadFromFile("obrazek.png");
	
	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");
		sf::Text xd("xd", font, 5000);
		xd.setFillColor(sf::Color::Red);
		xd.setPosition(200, 200);


	m_mushroom.setTexture(m_mushroomTexture);
	m_mushroom.setPosition(m_start.x* 32, m_start.y* 32);
	m_scale = sf::Vector2f (0.2, 0.2);
	m_mushroom.scale(m_scale);
	m_increment = sf::Vector2i(0, 0); //pixeli na sek
	m_isDone = false;
	
}

Game::~Game() 
{
	instance = nullptr;
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

Game * Game::getInstance()
{
	return instance;
}

void Game::Update() 
{
	m_window.Update();
	MoveMushroom(m_counter);
}

void Game::MoveMushroom(fpsCounter& counter)
{
	
	
	std::cout<< m_tilemap.mapa1[6][0];
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();
	//if (m_tilemap.mapa1[(int)m_mushroom.getPosition().y/32][(int)m_mushroom.getPosition().x/32] == 3)
	//{
	//	m_mushroom.setPosition(5* 32, 5* 32);
	//}


	if ((m_tilemap.mapa1[((int)m_mushroom.getPosition().y / 32) +1][((int)m_mushroom.getPosition().x / 32)] == 3)&& (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32][((int)m_mushroom.getPosition().x / 32) -1] == 3))
	{
		m_increment.x = 0;
		m_increment.y = speed_y;
	}
	else if ((m_tilemap.mapa1[((int)m_mushroom.getPosition().y / 32) - 1][((int)m_mushroom.getPosition().x / 32)] == 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32][((int)m_mushroom.getPosition().x / 32) - 1] == 3))
	{
		m_increment.x = 0;
		m_increment.y = -speed_y;
	}
	else if ((m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32][((int)m_mushroom.getPosition().x / 32) + 1] == 3)&& (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32+1][((int)m_mushroom.getPosition().x / 32)] != 3))
	{
		m_increment.y = 0;
		m_increment.x = speed_x;
	}
	else if ((m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32-1][((int)m_mushroom.getPosition().x / 32)] != 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32][((int)m_mushroom.getPosition().x / 32+1)] != 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32+1][((int)m_mushroom.getPosition().x / 32 + 1)] == 3))
	{
		m_increment.y = 0;
		m_increment.x = speed_x;
	}
	else if ((m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32 - 1][((int)m_mushroom.getPosition().x / 32)] != 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32][((int)m_mushroom.getPosition().x / 32 + 1)] != 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32 + 1][((int)m_mushroom.getPosition().x / 32 + 1)] != 3) && (m_tilemap.mapa1[(int)m_mushroom.getPosition().y / 32 + 2][((int)m_mushroom.getPosition().x / 32)] == 3))
	{
		m_increment.y = speed_y;
		m_increment.x = 0;
	}
	float fElapsed = TimePerFrame.asSeconds();
	sf::Vector2i m_prev((int)m_mushroom.getPosition().y, (int)m_mushroom.getPosition().x);
	m_mushroom.setPosition(
		m_mushroom.getPosition().x + (m_increment.x * fElapsed),
		m_mushroom.getPosition().y+ (m_increment.y * fElapsed));



	if ((m_mushroom.getPosition().y >= m_window.GetWindowSize().y) || (m_mushroom.getPosition().x >= m_window.GetWindowSize().x))
	{
		counter.hp -= 3;
	}




	//(m_increment.y * fElapsed)
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_tilemap);
	m_window.Draw(m_mushroom);
	//m_window.Draw(fpser);
	//m_window.Draw(m_hp);
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

*/
