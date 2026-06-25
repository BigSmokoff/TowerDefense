#pragma once
#include "SFML/Graphics.hpp"
#include "../GameObjects/Tower.h"
#include "EventHandler.h"
#include <string>

class UIManager
{
public:
	UIManager(std::vector<std::unique_ptr<Tower>>& towers);
	~UIManager() = default;

	void updateGold(unsigned int gold);
	void updateHealth(unsigned int health);
	void render(sf::RenderWindow& window);
	void update(sf::Time deltaTime, sf::Vector2f mousePos);
	bool isValidPlacement(sf::Vector2f position);

private:
	sf::Font font;
	sf::Text goldCounter;
	sf::Text townHealth;
	sf::RectangleShape ghostTower;
	std::vector<std::unique_ptr<Tower>>& towers;
};