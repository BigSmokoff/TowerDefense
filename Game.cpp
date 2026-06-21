#include "Game.h"

Game::Game(std::pair<unsigned int, unsigned int> windowSize, const char* name)
{
	window = sf::RenderWindow(sf::VideoMode({ windowSize.first, windowSize.second }), name);
}

void Game::run()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		processEvents();

		sf::Time deltaTime;

		deltaTime = clock.restart();

		update(deltaTime);

		render();
	}
}

void Game::update(sf::Time deltaTime)
{

}

void Game::processEvents()
{
	while (std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();

		}
	}
}

void Game::render()
{
	window.clear();

	window.display();
}
