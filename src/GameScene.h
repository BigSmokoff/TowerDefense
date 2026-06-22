#pragma once
#include "SFML/Graphics.hpp"
#include "IScene.h"
#include "GameObject.h"
#include "MonsterFactory.h"

class GameScene : public IScene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

	SceneType processEvent(const sf::Event& event) override;

private:
	std::vector<std::unique_ptr<GameObject>> entities;
	MonsterFactory factory;
	float spawnTimer = 0.0f;
};