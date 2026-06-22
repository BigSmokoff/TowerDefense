#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	virtual void render(sf::RenderWindow& window) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual bool isDead() const = 0;
	virtual sf::FloatRect getBounds() const = 0;
};