#include "PlayerState.h"

PlayerState::PlayerState(unsigned int gold) 
	: gold(gold)
{
}

void PlayerState::addGold(unsigned int amount)
{
	gold += amount;
}

unsigned int PlayerState::getGold() const
{
	return gold;
}

bool PlayerState::spendGold(unsigned int amount)
{
	if (gold >= amount)
	{
		gold -= amount;
		return true;
	}

	return false;
}
