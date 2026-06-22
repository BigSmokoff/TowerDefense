#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class Monster : public GameObject
{
public:
	Monster(sf::Vector2f size, sf::Vector2f pos, sf::Color color, float speed);
	~Monster() = default;

	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

	bool isDead() const override;

private:
	sf::RectangleShape sprite;
	float speed;
	bool dead = false;
};