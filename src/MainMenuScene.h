#pragma once
#include "SFML/Graphics.hpp"
#include "IScene.h"

class MainMenuScene : public IScene
{
public:
	MainMenuScene(float radius);
	~MainMenuScene() = default;

private:
	void render(sf::RenderWindow& window) override;

	void update(sf::Time deltaTime) override;

	SceneType processEvent(const sf::Event& event) override;

private:
	sf::CircleShape circle;
};