#include "GameScene.h"
#include "Monster.h"
#include <memory>


GameScene::GameScene()
{
	entities.push_back(std::make_unique<Monster>
		(sf::Vector2f(50.0f, 70.0f), sf::Vector2f(0.0f, 70.0f), sf::Color::Blue, 150.0f));
	entities.push_back(std::make_unique<Monster>
		(sf::Vector2f(70.0f, 70.0f), sf::Vector2f(0.0f, 150.0f), sf::Color::Green, 100.0f));
	entities.push_back(std::make_unique<Monster>
		(sf::Vector2f(50.0f, 100.0f), sf::Vector2f(0.0f, 400.0f), sf::Color::White, 50.0f));
}

void GameScene::render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->render(window);
	}
}

void GameScene::update(sf::Time deltaTime)
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->update(deltaTime);
	}
}

SceneType GameScene::processEvent(const sf::Event& event)
{
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->code == sf::Keyboard::Key::Space)
		{
			return SceneType::MainMenu;
		}
	}
	return SceneType::None;
}
