#pragma once
#include "GameObject.h"

class Tower : public GameObject
{
public:
	Tower(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	virtual ~Tower() = default;

	void render(sf::RenderWindow& window) override;
	void update(sf::Time deltaTime) override;
	bool isDead() const override;
	sf::FloatRect getBounds() const override;
	void kill() override;

private:
	sf::RectangleShape sprite;
};