#include "../Scenes/MainMenuScene.h"

MainMenuScene::MainMenuScene(float radius)
	: circle(radius)
{
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition({ 600, 500 });
	eventHandler.bindInput(sf::Keyboard::Key::Space, Action::StartGame);
	eventHandler.addCallback(Action::StartGame, [this](sf::Vector2i) { nextScene = SceneType::GamePlay; });
}

void MainMenuScene::render(sf::RenderWindow& window)
{
	window.draw(circle);
}

SceneType MainMenuScene::update(sf::Time deltaTime)
{
	return SceneType::None;
}

SceneType MainMenuScene::processEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	nextScene = SceneType::None;
	eventHandler.processEvent(event, window);

	return nextScene;
}