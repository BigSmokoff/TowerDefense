#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Level
{
public:
	Level(std::vector<sf::Vector2f> waypoints);
	~Level() = default;

	std::vector<sf::Vector2f> waypoints;
};