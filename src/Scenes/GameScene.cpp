#include "../Scenes/GameScene.h"
#include "../Core/Config.h"
#include "../GameObjects/Monster.h"
#include "../GameObjects/Projectile.h"
#include <memory>
#include <vector>
#include <cmath>

GameScene::GameScene()
{
	// подписываемся на изменение золота
	playerState.onGoldChanged = [this](unsigned int newGold)
		{
			uiManager.updateGold(newGold);
		};

	// Подписываемся на изменение здоровья ратуши
	townHall.onHealthChanged = [this](int newHealth)
		{
			uiManager.updateHealth(newHealth);
		};

	// иницализируем начальными значениями
	playerState.addGold(50);
	townHall.updateHealth(1000);

	waveManager.onReachedBase = [this]() { townHall.takeDamage(1); };

	eventHandler.bindInput(sf::Keyboard::Key::Space, Action::BackToMenu);
	eventHandler.bindInput(sf::Mouse::Button::Left, Action::PlaceTheTower);
	eventHandler.addCallback(Action::BackToMenu, [this](sf::Vector2i) { nextScene = SceneType::MainMenu; });
	eventHandler.addCallback(Action::PlaceTheTower, [this](sf::Vector2i mousePos)
		{
			if (playerState.spendGold(50))
			{
				float sizeX = 50.0f, sizeY = 50.0f;

				sf::Vector2f spawnPos(
					static_cast<float>(mousePos.x) - sizeX / 2.0f,
					static_cast<float>(mousePos.y) - sizeY / 2.0f
				);

				towers.push_back(std::make_unique<Tower>(
					sf::Vector2f(sizeX, sizeY),
					spawnPos,
					sf::Color::Green
				));
			}
		});
}

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

	if (townHall.isDead()) return SceneType::GameOver;

	townHall.update(deltaTime);

	// запускаем update каждому монстру
	for (const auto& monster : monsters)
	{
		monster->update(deltaTime);
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

	return SceneType::None;
}

SceneType GameScene::processEvent(const sf::Event& event)
{
	nextScene = SceneType::None;
	eventHandler.processEvent(event);

	return nextScene;
}
