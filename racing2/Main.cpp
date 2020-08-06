#define SDL_MAIN_HANDLED
#include "Game.h"

Game* game = nullptr;
int main(int argc, char* argv[])
{
	game = new Game();
	game->init("GameWindow", 900, 900);
	game->init("GameWindow", 900, 900);

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;
	while (game->running())
	{
		end = start;
		start = std::chrono::steady_clock::now();
		std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>( start - end);
		game->handleEvents();
		game->update(duration);
		game->render();
	}

	game->clean();
	return 0;
}
