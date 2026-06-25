#pragma once
#include "SFML/Graphics.hpp"
#include "../Scenes/SceneType.h"
#include <map>
#include <variant>

// объединяем клавиатуру и мышь в один тип
using InputTrigger = std::variant<sf::Keyboard::Key, sf::Mouse::Button>;

enum class Action
{
	StartGame,
	PlaceTheTower,
	BackToMenu
};

class EventHandler
{
public:
	EventHandler() = default;
	~EventHandler() = default;

	void processEvent(const sf::Event& event, const sf::RenderWindow& window);
	void bindInput(InputTrigger trigger, Action action);
	void addCallback(Action action, std::function<void(sf::Vector2i mousePosition)> callback);

private:
	// мап действий на вызовы
	std::map<Action, std::function<void(sf::Vector2i)>> callbacks;
	// мап биндов реальных кнопок на enum Action
	std::map<InputTrigger, Action> bindings;
};