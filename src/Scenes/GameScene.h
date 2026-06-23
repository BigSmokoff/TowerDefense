#pragma once
#include "SFML/Graphics.hpp"
#include "../GameObjects/TownHall.h"
#include "../GameObjects/Tower.h"
#include "../Scenes/IScene.h"
#include "../Scenes/WaveManager.h"
#include "../Managers/MonsterFactory.h"
#include "../Managers/PlayerState.h"
#include "../Managers/UIManager.h"

class GameScene : public IScene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void render(sf::RenderWindow& window) override;
	SceneType update(sf::Time deltaTime) override;
	SceneType processEvent(const sf::Event& event) override;

private:
	std::vector<std::unique_ptr<GameObject>> monsters;
	std::vector<std::unique_ptr<GameObject>> projectiles;
	std::vector<std::unique_ptr<Tower>> towers;
	TownHall townHall = TownHall({ 80.0f, 80.0f }, { 800.0f, 300.0f }, sf::Color::Blue, 5);
	WaveManager waveManager = WaveManager(monsters);
	PlayerState playerState = PlayerState(50);
	UIManager uiManager;
};