#include "GameScene.h"
#include "Monster.h"
#include <memory>
#include <vector>
#include <iostream>

void GameScene::render(sf::RenderWindow& window)
{
	for (const auto& entity : entities)
	{
		entity->render(window);
	}

	if (!townHall.isDead())
		townHall.render(window);
}

SceneType GameScene::update(sf::Time deltaTime)
{
	// спавн монстров каждые 1 сек
	spawnTimer += deltaTime.asSeconds();

	if (spawnTimer >= 1.0f)
	{
		entities.push_back(factory.createBasicMonster(300.0f));
		spawnTimer = 0.0f;
	}

	if (townHall.isDead()) return SceneType::MainMenu;

	townHall.update(deltaTime);

	// запускаем update каждому мобу
	for (const auto& entity : entities)
	{
		entity->update(deltaTime);

		// если моб настиг ратушу
		if (entity->getBounds().findIntersection(townHall.getBounds()))
		{
			townHall.takeDamage(1);

			// временное убийство монстра когда он нанес урон
			dynamic_cast<Monster*>(entity.get())->kill();
		}
	}

	// удаляем "мертвых мобов"
	std::erase_if(entities, [](const std::unique_ptr<GameObject>& obj) { return obj->isDead(); });

	return SceneType::None;
}

SceneType GameScene::processEvent(const sf::Event& event)
{
	// обработка события смены сцены (нажатый пробел)
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->code == sf::Keyboard::Key::Space)
		{
			return SceneType::MainMenu;
		}
	}
	return SceneType::None;
}
