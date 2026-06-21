#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Game
{
public:
	Game() = delete;

	Game(std::pair<unsigned int, unsigned int> windowSize, const char* name);

	~Game() = default;

	void run();

private:
	sf::RenderWindow window;

	void update(sf::Time deltaTime);

	void processEvents();

	void render();
};

