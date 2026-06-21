#pragma once
#include "SFML/Graphics.hpp"
#include "IScene.h"

class GameScene : public IScene
{

public:
	GameScene(sf::Vector2f size, float speed);
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

	SceneType GameScene::handleInput(const sf::Event& event);

private:
	sf::RectangleShape rect;
	float speed;
};