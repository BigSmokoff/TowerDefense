#pragma once
#include "../GameObjects/GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile(sf::Vector2f startPos, sf::Vector2f direction, sf::Color color, float speed, float radius, unsigned int damage);
	virtual ~Projectile() = default;

	void render(sf::RenderWindow& window) override;
	void update(sf::Time deltaTime) override;
	bool isDead() const override;
	sf::FloatRect getBounds() const override;
	void kill();
	unsigned int getDamage() const override;

private:
	sf::CircleShape sprite;
	sf::Vector2f direction;
	float speed;
	bool dead = false;
	unsigned int damage;
};