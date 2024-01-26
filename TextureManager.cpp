#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* file_name, SDL_Renderer* ren)
{
	SDL_Surface* temp_surface = IMG_Load(file_name);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, temp_surface);

	SDL_FreeSurface(temp_surface);
	return tex;
}
