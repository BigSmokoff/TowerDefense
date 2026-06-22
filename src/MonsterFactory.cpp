#include "MonsterFactory.h"
#include "Monster.h"

std::unique_ptr<GameObject> MonsterFactory::createBasicMonster(float startY)
{
	return std::make_unique<Monster>(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(0.0f, startY), sf::Color::Red, 150.0);
}
