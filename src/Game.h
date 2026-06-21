#pragma once
#include <SFML/Graphics.hpp>
#include <string_view>
#include "IScene.h"
#include <memory>

class Game
{
public:
	Game(sf::Vector2u windowSize, std::string_view name);

	~Game() = default;

	void run();

private:
	sf::RenderWindow window;
	std::unique_ptr<IScene> currentScene;

	void update(sf::Time deltaTime);

	void processEvents();

	void render();
};

