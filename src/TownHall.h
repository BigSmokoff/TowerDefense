#pragma once
#include "GameObject.h"

class TownHall : public GameObject
{
public:
	TownHall(sf::Vector2f size, sf::Vector2f startPos, sf::Color color, int health);
	virtual ~TownHall() = default;

	void render(sf::RenderWindow& window) override;
	void update(sf::Time deltaTime) override;
	bool isDead() const override;
	sf::FloatRect getBounds() const override;

	void takeDamage(int damage);
	int getHealth() const;

private:
	sf::RectangleShape sprite;
	int health;
};