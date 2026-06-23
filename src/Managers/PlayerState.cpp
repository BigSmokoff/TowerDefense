#include "../Managers/PlayerState.h"

void PlayerState::addGold(unsigned int amount)
{
	gold += amount;

	if (onGoldChanged)
	{
		onGoldChanged(gold);
	}
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

		if (onGoldChanged)
		{
			onGoldChanged(gold);
		}

		return true;
	}

	return false;
}
