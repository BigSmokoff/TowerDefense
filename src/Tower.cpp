#include "Tower.h"

Tower::Tower(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	sprite.setSize(size);
	sprite.setPosition(pos);
	sprite.setFillColor(color);
}

void Tower::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Tower::update(sf::Time deltaTime)
{
}

bool Tower::isDead() const
{
	return false;
}

sf::FloatRect Tower::getBounds() const
{
	return sprite.getGlobalBounds();
}

void Tower::kill()
{
}