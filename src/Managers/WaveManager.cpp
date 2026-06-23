#include "../Managers/WaveManager.h"

WaveManager::WaveManager(std::vector<std::unique_ptr<GameObject>>& monstersRef)
	: monstersRef(monstersRef)
{
}

void WaveManager::update(sf::Time deltaTime)
{
	spawnTimer -= deltaTime.asSeconds();

	if (spawnTimer <= 0)
	{
		monstersRef.push_back(factory.createBasicMonster(300.0f));
		spawnTimer = spawnInterval;
		++spawnedMonsters;
	}

	if (spawnedMonsters >= 5)
	{
		nextWave();
		spawnTimer = waveInterval;
		spawnedMonsters = 0;
	}
}

void WaveManager::nextWave()
{
	switch (++currentWave)
	{
	case 2:
		spawnInterval = 1.5f;
		break;
	case 3:
		spawnInterval = 1.0f;
		break;
	default:
		spawnInterval = 1.0f;
		break;
	}
}
