#pragma once
#include "SFML/Graphics.hpp"
#include "../Scenes/IScene.h"
#include "../Managers/EventHandler.h"

class GameOverScene : public IScene
{
public:
	GameOverScene();
	~GameOverScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event) override;

private:
	sf::Font font;
	sf::Text title;
	sf::Text subtitle;
	EventHandler eventHandler;
	SceneType nextScene = SceneType::None;
};