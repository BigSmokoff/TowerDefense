#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class Monster : public GameObject
{
public:
	Monster(sf::Vector2f size, sf::Vector2f pos, sf::Color color, float speed);
	~Monster() = default;

private:
	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

private:
	sf::RectangleShape sprite;
	sf::Vector2f size;
	sf::Color color;
	float speed;
};