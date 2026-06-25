#include "EventHandler.h"

void EventHandler::bindInput(InputTrigger trigger, Action action)
{
	bindings.emplace(trigger, action);
}

void EventHandler::addCallback(Action action, std::function<void(sf::Vector2i mousePosition)> callback)
{
	callbacks.emplace(action, callback);
}

void EventHandler::processEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	InputTrigger triggeredInput;
	sf::Vector2i mousePosition(0, 0);
	bool hasInput = false;

	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		triggeredInput = keyPressed->code;
		hasInput = true;

	}
	else if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
	{
		triggeredInput = mousePressed->button;
		sf::Vector2f worldPos = window.mapPixelToCoords(mousePressed->position);

		mousePosition = sf::Vector2i(static_cast<int>(worldPos.x), static_cast<int>(worldPos.y));
		hasInput = true;
	}

	if (hasInput)
	{
		auto itAction = bindings.find(triggeredInput);
		if (itAction != bindings.end())
		{
			auto itCallback = callbacks.find(itAction->second);
			if (itCallback != callbacks.end())
			{
				itCallback->second(mousePosition);
			}
		}
	}
}