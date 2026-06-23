#include "../Scenes/GameScene.h"
#include "../Core/Config.h"
#include "../GameObjects/Monster.h"
#include "../GameObjects/Projectile.h"
#include <memory>
#include <vector>
#include <cmath>

void GameScene::render(sf::RenderWindow& window)
{
	for (const auto& entity : monsters)
	{
		entity->render(window);
	}

	// для ратуши доп. проверка так как она не ptr
	if (!townHall.isDead())
		townHall.render(window);

	for (const auto& tower : towers)
	{
		tower->render(window);
	}

	for (const auto& projectile : projectiles)
	{
		projectile->render(window);
	}

	uiManager.render(window);
}

SceneType GameScene::update(sf::Time deltaTime)
{
	waveManager.update(deltaTime);

	if (townHall.isDead()) return SceneType::MainMenu;

	townHall.update(deltaTime);

	// запускаем update каждому монстру
	for (const auto& monster : monsters)
	{
		monster->update(deltaTime);

		// если монстр настиг ратушу
		if (monster->getBounds().findIntersection(townHall.getBounds()))
		{
			townHall.takeDamage(1);

			// временное убийство монстра когда он нанес урон
			monster->kill();
		}
	}

	// обновляем башни и запускаем снаряды
	for (const auto& tower : towers)
	{
		tower->update(deltaTime);

		if (tower->canShoot())
		{
			GameObject* target = nullptr;
			float minDistance = tower->getRange();
			for (const auto& monster : monsters)
			{
				float dx = monster->getPosition().x - tower->getPosition().x;
				float dy = monster->getPosition().y - tower->getPosition().y;

				float distanceToTarget = std::sqrt(dx * dx + dy * dy);

				// находим ближайшую цель
				if (distanceToTarget < minDistance)
				{
					target = monster.get();
					minDistance = distanceToTarget;
				}
			}

			// если нашли добавляем в снаряд в вектор и сбрсываем таймер
			if (target == nullptr) continue;

			sf::Vector2f direction = target->getPosition() - tower->getPosition();
			direction = direction.normalized();
			float x = tower->getPosition().x + tower->getSize().x / 2.0f;
			float y = tower->getPosition().y + tower->getSize().y / 2.0f;

			projectiles.push_back(std::make_unique<Projectile>
				(sf::Vector2f(x, y), direction, sf::Color::Yellow, 400.0f, 10.0f));

			tower->resetCooldown();
		}
	}

	// обновляем снаряды и если попадание то убиваем и монстра и снаряд
	for (const auto& projectile : projectiles)
	{
		projectile->update(deltaTime);

		for (const auto& monster : monsters)
		{
			if (monster->getBounds().findIntersection(projectile->getBounds()))
			{
				monster->kill();
				projectile->kill();
				playerState.addGold(10);
				break;
			}
		}
	}

	// удаляем "мертвых сущностей"
	std::erase_if(monsters, [](const std::unique_ptr<GameObject>& obj) { return obj->isDead(); });
	std::erase_if(projectiles, [](const std::unique_ptr<GameObject>& obj) { return obj->isDead(); });

	uiManager.update(std::to_string(playerState.getGold()), std::to_string(townHall.getHealth()));

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

	// добавление в вектор башен, при нажатии лкм 
	if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
	{
		if (mousePressed->button == sf::Mouse::Button::Left)
		{
			// если достаточно денег то ставим башню
			if (playerState.spendGold(50))
			{
				float sizeX = 50.0f, sizeY = 50.0f;
				towers.push_back(std::make_unique<Tower>(
					sf::Vector2f(sizeX, sizeY),
					sf::Vector2f(mousePressed->position.x - sizeX / 2, mousePressed->position.y - sizeY / 2),
					sf::Color::Green)
				);
			}
		}
	}
	return SceneType::None;
}
