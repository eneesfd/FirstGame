#include <iostream>
#include <memory>
#include "Game.h"


int main(int argc, char* argv[])
{
	constexpr int fps = 60;
	constexpr  int frame_delay = 100 / fps;

	Uint32 frame_start;
	int frame_time;


	std::unique_ptr<Game> game = std::make_unique<Game>("FirstGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->runnig())
	{
		frame_start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frame_time = SDL_GetTicks() - frame_start;

		if(frame_delay > frame_time)
		{
			SDL_Delay(frame_delay - frame_time);
		}

	}

    return 0;

}
