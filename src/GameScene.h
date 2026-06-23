#pragma once
#include "SFML/Graphics.hpp"
#include "TownHall.h"
#include "IScene.h"
#include "MonsterFactory.h"
#include "Tower.h"

class GameScene : public IScene
{
public:
	GameScene();
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event) override;

private:
	std::vector<std::unique_ptr<GameObject>> monsters;
	std::vector<std::unique_ptr<GameObject>> projectiles;
	std::vector<std::unique_ptr<Tower>> towers;
	TownHall townHall = TownHall({ 80.0f, 80.0f }, { 800.0f, 300.0f }, sf::Color::Blue, 5);
	MonsterFactory factory;
	float spawnTimer = 0.0f;
	sf::Font font;
	unsigned int gold = 50;
	sf::Text goldCounter;
	sf::Text townHealth;
};