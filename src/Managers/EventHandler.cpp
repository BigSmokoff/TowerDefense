#include "EventHandler.h"

void EventHandler::bindInput(InputTrigger trigger, Action action)
{
	bindings.emplace(trigger, action);
}

void EventHandler::addCallback(Action action, std::function<void(sf::Vector2i mousePos)> callback)
{
	callbacks.emplace(action, callback);
}

void EventHandler::processEvent(const sf::Event& event)
{
	InputTrigger triggeredInput;
	sf::Vector2i mousePos(0, 0);
	bool hasInput = false;

	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		triggeredInput = keyPressed->code;
		hasInput = true;

	}
	else if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
	{
		triggeredInput = mousePressed->button;
		mousePos = mousePressed->position;
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
				itCallback->second(mousePos);
			}
		}
	}
}