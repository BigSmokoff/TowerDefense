#include "GameScene.h"
#include "Monster.h"
#include <memory>
#include <vector>

void GameScene::render(sf::RenderWindow& window)
{
	for (const auto& entity : entities)
	{
		entity->render(window);
	}
}

void GameScene::update(sf::Time deltaTime)
{
	spawnTimer += deltaTime.asSeconds();

	if (spawnTimer >= 2.0f)
	{
		entities.push_back(factory.createBasicMonster(300.0f));
		spawnTimer = 0.0f;
	}

	for (const auto& entity : entities)
	{
		entity->update(deltaTime);
	}

	std::erase_if(entities, [](const std::unique_ptr<GameObject>& obj) { return obj->isDead(); });

}

SceneType GameScene::processEvent(const sf::Event& event)
{
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->code == sf::Keyboard::Key::Space)
		{
			return SceneType::MainMenu;
		}
	}
	return SceneType::None;
}
