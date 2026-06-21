#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(float radius)
	: circle(radius)
{
	circle.setFillColor(sf::Color::Blue);

	circle.setPosition({ 600, 500 });
}

void MainMenuScene::render(sf::RenderWindow& window)
{
	window.draw(circle);
}

void MainMenuScene::update(sf::Time deltaTime)
{
}

SceneType MainMenuScene::handleInput(const sf::Event& event)
{
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->code == sf::Keyboard::Key::Space)
		{
			return SceneType::GamePlay;
		}
	}
	return SceneType::None;
}

