#include "../GameObjects/Tower.h"

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
	cooldownTimer -= deltaTime.asSeconds();
}

bool Tower::isDead() const
{
	return false;
}

sf::FloatRect Tower::getBounds() const
{
	return sprite.getGlobalBounds();
}

bool Tower::canShoot() const
{
	return cooldownTimer < 0;
}

void Tower::resetCooldown()
{
	cooldownTimer = 1.0f;
}

float Tower::getRange() const
{
	return range;
}

sf::Vector2f Tower::getPosition() const
{
	return sprite.getPosition();
}

sf::Vector2f Tower::getSize() const
{
	return sprite.getSize();
}