#pragma once
#include "SFML/Graphics.hpp"
#include "../Scenes/SceneType.h"

class IScene
{
public:
	IScene() = default;
	virtual ~IScene() = default;

	// объ€вление чистой виртуальной функции, 
	// = 0 говорим компил€тору что класс абстрактный
	virtual void render(sf::RenderWindow& window) = 0;
	virtual SceneType update(sf::Time deltaTime) = 0;
	virtual SceneType processEvent(const sf::Event& event) = 0;
};