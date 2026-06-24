#pragma once
#include "../GameObjects/GameObject.h"
#include "../GameObjects/TownHall.h"
#include <memory>

class MonsterFactory
{
public:
	MonsterFactory() = default;
	~MonsterFactory() = default;

	std::unique_ptr<GameObject> createBasicMonster(const std::vector<sf::Vector2f>& waypoints, std::function<void()> onBaseReachedCallback);

private:
	sf::Vector2f monsterSize = sf::Vector2f(50.0f, 50.0f);
	sf::Color    monsterColor = sf::Color::Red;
	float        movementSpeed = 200.0f;
};