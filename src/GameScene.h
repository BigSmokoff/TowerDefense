#pragma once
#include "SFML/Graphics.hpp"
#include "TownHall.h"
#include "IScene.h"
#include "MonsterFactory.h"
#include "Tower.h"

class GameScene : public IScene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event) override;

private:
	std::vector<std::unique_ptr<GameObject>> entities;
	std::vector<std::unique_ptr<Tower>> towers;
	MonsterFactory factory;
	TownHall townHall = TownHall({ 80.0f, 80.0f }, { 800.0f, 300.0f }, sf::Color::Blue, 5);
	float spawnTimer = 0.0f;
};