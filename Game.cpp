#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;


Game::Game(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	init(title, x_pos, y_pos, width, height, fullscreen);
}

Game::~Game()
{
	clean();
}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	int	flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!...\n";
		window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
		if(window_)
		{
			std::cout << "Window created!\n";
		}
		renderer_ = SDL_CreateRenderer(window_, -1, 0);
		if (renderer_)
		{
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
			std::cout << "Renderer Created!\n";
		}
		is_running_ = true;
	}else
	{
		is_running_ = false; 
	}

	player = new GameObject("assets/logandribbble.gif", renderer_);
}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		is_running_ = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();
}

void Game::render()
{
	SDL_RenderClear(renderer_);
	player->render();
	SDL_RenderPresent(renderer_);
}

void Game::clean()
{
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
	std::cout << "Game Cleaned!\n";
}








