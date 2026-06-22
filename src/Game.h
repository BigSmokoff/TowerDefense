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
	void changeScene(SceneType nextScene);

private:
	void update(sf::Time deltaTime);
	void processEvents();
	void render();

private:
	sf::RenderWindow window;
	// делаем IScene чтобы можно было переключаться между сценами
	std::unique_ptr<IScene> currentScene;
};

