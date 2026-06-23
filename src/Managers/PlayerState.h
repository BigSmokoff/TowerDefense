#pragma once

class PlayerState
{
public:
	PlayerState(unsigned int gold);
	~PlayerState() = default;

	void addGold(unsigned int amount);
	unsigned int getGold() const;
	bool spendGold(unsigned int amount);

private:
	unsigned int gold = 50;
};