#pragma once
#include "SFML/Graphics.hpp"
#include "../GameObjects/TownHall.h"
#include "../GameObjects/Tower.h"
#include "../Scenes/IScene.h"
#include "../Managers/WaveManager.h"
#include "../Managers/PlayerState.h"
#include "../Managers/UIManager.h"
#include "../Managers/EventHandler.h"

class GameScene : public IScene
{
public:
	GameScene();
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event) override;

private:
	std::vector<std::unique_ptr<GameObject>> monsters;
	std::vector<std::unique_ptr<GameObject>> projectiles;
	std::vector<std::unique_ptr<Tower>> towers;
	TownHall townHall = TownHall({ 80.0f, 80.0f }, { 800.0f, 300.0f }, sf::Color::Blue, 0);
	WaveManager waveManager = WaveManager(monsters);
	PlayerState playerState;
	UIManager uiManager;
	EventHandler eventHandler;
	SceneType nextScene = SceneType::None;
};