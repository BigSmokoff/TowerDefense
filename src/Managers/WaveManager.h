#pragma once
#include "../GameObjects/GameObject.h"
#include "../Factories/MonsterFactory.h"
#include <vector>
#include <memory>

class WaveManager
{
public:
	WaveManager(std::vector<std::unique_ptr<GameObject>>& monstersRef);
	~WaveManager() = default;

	void update(sf::Time deltaTime);
	void nextWave();

private:
	std::vector<std::unique_ptr<GameObject>>& monstersRef;
	MonsterFactory factory;
	float spawnInterval = 2.0f;
	float spawnTimer = spawnInterval;
	int currentWave = 1;
	int spawnedMonsters = 0;
	float waveInterval = 5.0f;
};