#pragma once
#include "SFML/Graphics.hpp"
#include "../Scenes/IScene.h"
#include "../Managers/EventHandler.h"

class MainMenuScene : public IScene
{
public:
	MainMenuScene(float radius);
	~MainMenuScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event, const sf::RenderWindow& window) override;

private:
	sf::CircleShape circle;
	EventHandler eventHandler;
	SceneType nextScene = SceneType::None;
};