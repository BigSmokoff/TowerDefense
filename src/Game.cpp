#include "Game.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "SceneType.h"
#include <memory>

Game::Game(sf::Vector2u windowSize, std::string_view name) :
	window(sf::VideoMode({ windowSize.x, windowSize.y }), name),
	currentScene(std::make_unique<MainMenuScene>(10.0f))
{
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
	currentScene->update(deltaTime);
}

void Game::processEvents()
{
	while (std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}

		SceneType nextScene = currentScene->handleInput(*event);

		switch (nextScene)
		{
		case SceneType::MainMenu:
			currentScene = std::make_unique<MainMenuScene>(10.0f);
			break;
		case SceneType::GamePlay:
			currentScene = std::make_unique<GameScene>(sf::Vector2f({ 300.0f, 300.0f }), 150.0f);
			break;
		case SceneType::None:
			break;
		default:
			break;
		}
	}
}

void Game::render()
{
	window.clear();

	currentScene->render(window);

	window.display();
}
