#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class UIManager
{
public:
	UIManager();
	~UIManager() = default;

	void update(std::string gold, std::string townHealth);
	void render(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text goldCounter;
	sf::Text townHealth;
};