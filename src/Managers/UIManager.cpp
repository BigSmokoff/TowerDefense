#include "../Managers/UIManager.h"
#include "../Core/Config.h"

UIManager::UIManager()
	: font(), goldCounter(font), townHealth(font)
{
	if (font.openFromFile("assets/fonts/TILDASANS-VF.TTF"))
	{
		goldCounter.setCharacterSize(30);
		townHealth.setCharacterSize(30);
		goldCounter.setFillColor(sf::Color::White);
		townHealth.setFillColor(sf::Color::White);
		goldCounter.setPosition(sf::Vector2f(20.0f, Config::SCREEN_HEIGHT - 50.0f));
		townHealth.setPosition(sf::Vector2f(780.0f, 400.0f));
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
}

