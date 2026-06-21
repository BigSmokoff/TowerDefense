#include "GameScene.h"

GameScene::GameScene(sf::Vector2f size, float speed) 
	: rect(size), speed(speed)
{
	rect.setFillColor(sf::Color::Green);

	rect.setPosition({ 0, 300 });
}

void GameScene::render(sf::RenderWindow& window)
{
	window.draw(rect);
}


void GameScene::update(sf::Time deltaTime)
{
	sf::Vector2 offset = { speed * deltaTime.asSeconds(), 0.0f };

	rect.move(offset);
}

SceneType GameScene::handleInput(const sf::Event& event)
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
