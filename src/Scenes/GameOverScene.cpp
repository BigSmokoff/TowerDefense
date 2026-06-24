#include "../Scenes/GameOverScene.h"
#include "../Core/Config.h"

GameOverScene::GameOverScene()
	: font(), title(font), subtitle(font)
{
	if (font.openFromFile("assets/fonts/TILDASANS-VF.TTF"))
	{
		title.setCharacterSize(70);
		subtitle.setCharacterSize(30);

		title.setFillColor(sf::Color::White);
		subtitle.setFillColor(sf::Color::White);

		title.setString("GAME OVER");
		subtitle.setString("Press ENTER to return to Main Menu");

		sf::Vector2f titleCenter = title.getLocalBounds().getCenter();
		title.setOrigin(titleCenter);

		sf::Vector2f subtitleCenter = subtitle.getLocalBounds().getCenter();
		subtitle.setOrigin(subtitleCenter);

		title.setPosition(sf::Vector2f(Config::SCREEN_WIDTH / 2, Config::SCREEN_HEIGHT / 2));
		subtitle.setPosition(sf::Vector2f(Config::SCREEN_WIDTH / 2, Config::SCREEN_HEIGHT / 2 + 80.0f));

		eventHandler.bindInput(sf::Keyboard::Key::Enter, Action::BackToMenu);
		eventHandler.addCallback(Action::BackToMenu, [this](sf::Vector2i) { nextScene = SceneType::MainMenu; });
	}
}	

void GameOverScene::render(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(subtitle);
}

SceneType GameOverScene::update(sf::Time deltaTime)
{
	return SceneType::None;
}

SceneType GameOverScene::processEvent(const sf::Event& event)
{
	nextScene = SceneType::None;
	eventHandler.processEvent(event);

	return nextScene;
}

