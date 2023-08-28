#include "Game.h"

using namespace std;

std::unique_ptr<Game> game = nullptr;

int main(int argc, char* argv[])
{
	game = std::make_unique<Game>();
	game->init("Chapter xx1x", 100, 100, 640,480, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}