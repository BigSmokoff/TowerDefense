#pragma once
#include "../GameObjects/GameObject.h"
#include "../Managers/MonsterFactory.h"
#include "../Core/Level.h"
#include <vector>
#include <memory>

class WaveManager
{
public:
	WaveManager(std::vector<std::unique_ptr<GameObject>>& monstersRef);
	~WaveManager() = default;

	void update(sf::Time deltaTime);
	void nextWave();

	std::function<void()> onReachedBase;

private:
	std::vector<std::unique_ptr<GameObject>>& monstersRef;
	MonsterFactory factory;
	float spawnInterval = 1.5f;
	float spawnTimer = spawnInterval;
	int currentWave = 1;
	int spawnedMonsters = 0;
	float waveInterval = 15.0f;
	const sf::Vector2f townHall = sf::Vector2f(800.0f, 300.0f);
	std::vector<Level> levels = { Level({
		sf::Vector2f(50.0f, 600.0f),
		sf::Vector2f(450.0f, 400.0f),
		sf::Vector2f(150.0f, 200.0f),
		townHall
	}) };
};