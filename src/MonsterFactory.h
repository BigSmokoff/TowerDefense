#pragma once
#include "GameObject.h"
#include <memory>

class MonsterFactory
{
public:
	MonsterFactory() = default;
	~MonsterFactory() = default;

	std::unique_ptr<GameObject> createBasicMonster(float startY);
};