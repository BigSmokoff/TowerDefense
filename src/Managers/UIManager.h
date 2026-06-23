#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class UIManager
{
public:
	UIManager();
	~UIManager() = default;

	void updateGold(unsigned int gold);
	void updateHealth(unsigned int health);
	void render(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text goldCounter;
	sf::Text townHealth;
};