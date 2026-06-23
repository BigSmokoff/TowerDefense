#pragma once
#include <functional>

class PlayerState
{
public:
	PlayerState() = default;
	~PlayerState() = default;

	void addGold(unsigned int amount);
	unsigned int getGold() const;
	bool spendGold(unsigned int amount);

	std::function<void(unsigned int)> onGoldChanged;

private:
	unsigned int gold = 0;
};