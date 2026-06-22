#pragma once
#include "SFML/Graphics.hpp"
#include "IScene.h"
#include "GameObject.h"

class GameScene : public IScene
{
public:
	GameScene();
	~GameScene() = default;

private:
	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

	SceneType GameScene::processEvent(const sf::Event& event);

private:
	std::vector<std::unique_ptr<GameObject>> entities;
};