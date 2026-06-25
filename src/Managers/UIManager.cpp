#include "../Managers/UIManager.h"
#include "../Core/Config.h"

UIManager::UIManager(std::vector<std::unique_ptr<Tower>>& towers)
	: font(), goldCounter(font), townHealth(font), towers(towers)
{
	if (font.openFromFile("assets/fonts/TILDASANS-VF.TTF"))
	{
		goldCounter.setCharacterSize(30);
		townHealth.setCharacterSize(30);
		ghostTower.setSize(sf::Vector2f(50.0f, 50.0f));

		goldCounter.setFillColor(sf::Color::White);
		townHealth.setFillColor(sf::Color::White);
		ghostTower.setFillColor(sf::Color(0, 255, 0, 128));

		sf::Vector2f goldCounterCenter = goldCounter.getLocalBounds().getCenter();
		goldCounter.setOrigin(goldCounterCenter);
		sf::Vector2f townHealthCenter = townHealth.getLocalBounds().getCenter();
		townHealth.setOrigin(townHealthCenter);
		sf::Vector2f ghostTowerCenter = ghostTower.getLocalBounds().getCenter();
		ghostTower.setOrigin(ghostTowerCenter);

		goldCounter.setPosition(sf::Vector2f(20.0f, Config::SCREEN_HEIGHT - 50));
		townHealth.setPosition(sf::Vector2f(720.0f, 350.0f));
	}
}

bool UIManager::isValidPlacement(sf::Vector2f position)
{
	sf::Vector2f towerSize(50.0f, 50.0f);

	sf::Vector2f centeredPosition = position - (towerSize / 2.0f);

	sf::FloatRect towerRect = sf::FloatRect(centeredPosition, towerSize);
	for (const auto& tower : towers)
	{
		if (tower->getBounds().findIntersection(towerRect))
		{
			return false;
		}
	}

	return true;
}

void UIManager::update(sf::Time deltaTime, sf::Vector2f mousePos)
{
	ghostTower.setPosition(mousePos);

	if (isValidPlacement(mousePos))
	{
		ghostTower.setFillColor(sf::Color(0, 255, 0, 128));
	}
	else
	{
		ghostTower.setFillColor(sf::Color(255, 0, 0, 128));
	}
}

void UIManager::updateGold(unsigned int gold)
{
	goldCounter.setString("Gold: " + std::to_string(gold));
}

void UIManager::updateHealth(unsigned int health)
{
	townHealth.setString("Health: " + std::to_string(health));
}

void UIManager::render(sf::RenderWindow& window)
{
	window.draw(goldCounter);
	window.draw(townHealth);
	window.draw(ghostTower);
}
