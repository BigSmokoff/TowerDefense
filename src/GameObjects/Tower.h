#pragma once
#include "../GameObjects/GameObject.h"

class Tower : public GameObject
{
public:
	Tower(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	virtual ~Tower() = default;

	void render(sf::RenderWindow& window) override;
	void update(sf::Time deltaTime) override;
	bool isDead() const override;
	sf::FloatRect getBounds() const override;
	bool canShoot() const;
	void resetCooldown();
	float getRange() const;
	sf::Vector2f getPosition() const override;
	sf::Vector2f getSize() const;

private:
	sf::RectangleShape sprite;
	float range = 300.0f;
	float cooldownTimer = 1.0f;
};