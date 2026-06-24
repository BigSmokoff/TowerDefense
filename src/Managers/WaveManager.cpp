#include "../Managers/WaveManager.h"

WaveManager::WaveManager(std::vector<std::unique_ptr<GameObject>>& monstersRef)
	: monstersRef(monstersRef)
{
	levels.reserve(100);
}

void WaveManager::update(sf::Time deltaTime)
{
	spawnTimer -= deltaTime.asSeconds();

	if (spawnTimer <= 0)
	{
		monstersRef.push_back(factory.createBasicMonster(levels[currentWave - 1].waypoints, onReachedBase));

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
		spawnInterval = 1.2f;
		levels.push_back(Level({
			sf::Vector2f(50.0f, 50.0f),
			sf::Vector2f(50.0f, 580.0f),
			sf::Vector2f(850.0f, 580.0f),
			townHall
			}));
		break;

	case 3:
		spawnInterval = 1.0f;
		levels.push_back(Level({
			sf::Vector2f(100.0f, 100.0f),
			sf::Vector2f(600.0f, 100.0f),
			sf::Vector2f(600.0f, 450.0f),
			sf::Vector2f(200.0f, 450.0f),
			sf::Vector2f(200.0f, 250.0f),
			sf::Vector2f(450.0f, 250.0f),
			townHall
			}));
		break;

	case 4:
		spawnInterval = 0.8f;
		levels.push_back(Level({
			sf::Vector2f(50.0f, 325.0f),
			sf::Vector2f(700.0f, 580.0f),
			sf::Vector2f(200.0f, 580.0f),
			townHall
			}));
		break;

	case 5:
		spawnInterval = 0.6f;
		levels.push_back(Level({
			sf::Vector2f(50.0f, 580.0f),
			sf::Vector2f(500.0f, 325.0f),
			townHall
			}));
		break;

	default:
		spawnInterval = 0.5f;
		levels.push_back(Level({
			sf::Vector2f(50.0f, 120.0f),
			townHall
			}));
		break;
	}
}
