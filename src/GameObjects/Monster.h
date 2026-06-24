#pragma once
#include "SFML/Graphics.hpp"
#include "../GameObjects/GameObject.h"

class Monster : public GameObject
{
public:
	Monster(sf::Vector2f size, const std::vector<sf::Vector2f>& waypoints, sf::Color color, float speed);
	~Monster() = default;

	void render(sf::RenderWindow& window) override;
	void update(sf::Time deltaTime) override;
	bool isDead() const override;
	sf::FloatRect getBounds() const override;
	void kill() override;
	sf::Vector2f getPosition() const override;

	std::function<void()> onReachedBase;

private:
	sf::RectangleShape sprite;
	const std::vector<sf::Vector2f>& waypoints;
	float speed;
	bool dead = false;
	unsigned int currentWaypoint = 0;
};