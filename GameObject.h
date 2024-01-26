#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* texture_sheet, SDL_Renderer* ren);
	~GameObject();

	void update();
	void render();

private:
	int x_pos_;
	int y_pos_;

	SDL_Texture* object_texture_;
	SDL_Rect src_rect_, dest_rect_;
	SDL_Renderer* renderer_;
};

