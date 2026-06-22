#include "Monster.h"

Monster::Monster(sf::Vector2f size, sf::Vector2f startPos, sf::Color color, float speed)
	: size(size), color(color), speed(speed)
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
