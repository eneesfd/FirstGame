#pragma once


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
	Game() = default;
	Game(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
	~Game();
	void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
	void handle_events();
	void update();
	void render();
	void clean();

	bool runnig() { return  is_running_; }

private:
	int cnt_ = 0;
	bool is_running_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
};

