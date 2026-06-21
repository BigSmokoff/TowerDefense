#include "Game.h"
#include <utility>

int main()
{
	Game game({ 1270, 1080 }, "TowerDefense");

	game.run();

	return 0;
}