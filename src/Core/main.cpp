#include "../Core/Game.h"
#include "../Core/Config.h"
#include <utility>

int main()
{
	Game game({ Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT}, Config::GAME_NAME);

	game.run();

	return 0;
}