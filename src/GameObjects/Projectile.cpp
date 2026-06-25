#include "../GameObjects/Projectile.h"
#include "../Core/Config.h"

Projectile::Projectile(sf::Vector2f startPos, sf::Vector2f direction, sf::Color color, float speed, float radius, unsigned int damage)
	:  direction(direction), speed(speed), damage(damage)
{
	sprite.setRadius(radius);
	sprite.setPosition(startPos);
	sprite.setFillColor(color);
}

void Projectile::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Projectile::update(sf::Time deltaTime)
{
	bool outOfBounds = Config::SCREEN_HEIGHT <= sprite.getPosition().y ||
	                   Config::SCREEN_WIDTH <= sprite.getPosition().x ||
	                   0.0f >= sprite.getPosition().y ||
	                   0.0f >= sprite.getPosition().x;

	if (outOfBounds)
	{
		kill();
	}

	sprite.move(direction * deltaTime.asSeconds() * speed);
}

bool Projectile::isDead() const
{
	return dead;
}

sf::FloatRect Projectile::getBounds() const
{
	return sprite.getGlobalBounds();
}

void Projectile::kill()
{
	dead = true;
}

unsigned int Projectile::getDamage() const
{
	return damage;
}
