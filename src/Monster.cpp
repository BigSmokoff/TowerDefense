#include "Monster.h"
#include "Config.h"

Monster::Monster(sf::Vector2f size, sf::Vector2f startPos, sf::Color color, float speed)
	: speed(speed)
{
	sprite.setSize(size);
	sprite.setPosition(startPos);
	sprite.setFillColor(color);
}

void Monster::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Monster::update(sf::Time deltaTime)
{
	sf::Vector2 offset = { speed * deltaTime.asSeconds(), 0.0f };

	sprite.move(offset);
}

bool Monster::isDead() const
{
	return dead;
}

void Monster::kill()
{
	dead = true;
}

sf::FloatRect Monster::getBounds() const
{
	return sprite.getGlobalBounds();
}