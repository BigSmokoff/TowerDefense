#include "../GameObjects/Monster.h"
#include "../Core/Config.h"

Monster::Monster(sf::Vector2f size, const std::vector<sf::Vector2f>& waypoints, sf::Color color, float speed)
	: waypoints(waypoints), speed(speed)
{
	sprite.setSize(size);
	if (!waypoints.empty())
	{
		sf::Vector2f monsterCenter = sprite.getLocalBounds().getCenter();
		sprite.setOrigin(monsterCenter);
		sprite.setPosition(waypoints[currentWaypoint]);
	}
	sprite.setFillColor(color);

}

void Monster::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Monster::update(sf::Time deltaTime)
{
	if (waypoints.empty() || currentWaypoint >= waypoints.size())
		return;

	sf::Vector2f direction = waypoints[currentWaypoint] - sprite.getPosition();
	
	float townOffset = currentWaypoint == (waypoints.size() - 1) ? 85.0f : 0;

	// избавляемся от проскока используя speed * deltaTime.asSeconds(), 
	// следующий шаг должен быть меньше чем расстояние до точки
	if (direction.length() - townOffset < speed * deltaTime.asSeconds())
	{
		if (++currentWaypoint == waypoints.size())
		{
			onReachedBase();
			kill();
		}
		return;
	}

	direction = direction.normalized();
	sprite.move(speed * deltaTime.asSeconds() * direction);
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

sf::Vector2f Monster::getPosition() const
{
	return sprite.getPosition();
}