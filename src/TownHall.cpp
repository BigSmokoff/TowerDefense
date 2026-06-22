#include "TownHall.h"

TownHall::TownHall(sf::Vector2f size, sf::Vector2f startPos, sf::Color color, int health)
	: health(health)
{
	sprite.setSize(size);
	sprite.setPosition(startPos);
	sprite.setFillColor(color);
}

void TownHall::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void TownHall::update(sf::Time deltaTime)
{
}

bool TownHall::isDead() const
{
	return health <= 0;
}

sf::FloatRect TownHall::getBounds() const
{
	return sprite.getGlobalBounds();
}

void TownHall::takeDamage(int damage)
{
	health -= damage;
}

int TownHall::getHealth() const
{
	return health;
}