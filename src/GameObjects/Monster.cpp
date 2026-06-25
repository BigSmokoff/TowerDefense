#include "../GameObjects/Monster.h"
#include "../Core/Config.h"

Monster::Monster(sf::Vector2f size, const std::vector<sf::Vector2f>& waypoints, sf::Color color, float speed, int maxHealth)
	: waypoints(waypoints), speed(speed), maxHealth(maxHealth), currentHealth(maxHealth)
{
	sprite.setSize(size);
	healthBarBg.setSize(sf::Vector2f(50.0f, 5.0f));
	healthBarFill.setSize(sf::Vector2f(45.0f, 5.0f));

	if (!waypoints.empty())
	{
		sf::Vector2f monsterCenter = sprite.getLocalBounds().getCenter();
		sprite.setOrigin(monsterCenter);
		sprite.setPosition(waypoints[currentWaypoint]);

		sf::Vector2f barBgCenter = healthBarBg.getLocalBounds().getCenter();
		healthBarBg.setOrigin(barBgCenter);
		healthBarBg.setPosition(waypoints[currentWaypoint] - sf::Vector2f(2.0f, 50.0f));

		sf::Vector2f barFillCenter = healthBarFill.getLocalBounds().getCenter();
		healthBarFill.setOrigin(barFillCenter);
		healthBarFill.setPosition(waypoints[currentWaypoint] - sf::Vector2f(2.0f, 50.0f));
	}

	sprite.setFillColor(color);
	healthBarBg.setFillColor(sf::Color(66, 66, 66));
	healthBarFill.setFillColor(sf::Color::Green);
}

void Monster::render(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(healthBarBg);
	window.draw(healthBarFill);
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

	healthBarFill.setSize({ healthBarBg.getSize().x * (static_cast<float>(currentHealth) / maxHealth), 5.0f});
	healthBarBg.setPosition(sprite.getPosition() - sf::Vector2f(2.0f, 50.0f));
	healthBarFill.setPosition(sprite.getPosition() - sf::Vector2f(2.0f, 50.0f));
}

bool Monster::isDead() const
{
	return currentHealth <= 0;
}

void Monster::kill()
{
	currentHealth = 0;
}

void Monster::takeDamage(int damage)
{
	currentHealth -= damage;
}

sf::FloatRect Monster::getBounds() const
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Monster::getPosition() const
{
	return sprite.getPosition();
}