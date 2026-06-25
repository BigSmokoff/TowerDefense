#include "../Managers/MonsterFactory.h"
#include "../GameObjects/Monster.h"

std::unique_ptr<GameObject> MonsterFactory::createBasicMonster(const std::vector<sf::Vector2f>& waypoints, std::function<void()> onBaseReachedCallback)
{
	auto monster = std::make_unique<Monster>(monsterSize, waypoints, monsterColor, movementSpeed, 5);
	monster->onReachedBase = onBaseReachedCallback;
	return std::move(monster);
}
