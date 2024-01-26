#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texture_sheet, SDL_Renderer* ren)
{
	renderer_ = ren;
	object_texture_ = TextureManager::LoadTexture(texture_sheet, ren);
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
	x_pos_ = 0;
	y_pos_ = 0;

	src_rect_.h = 32;
	src_rect_.w = 32;
	src_rect_.x = 0;
	src_rect_.y = 0;

	dest_rect_.x = x_pos_;
	dest_rect_.y = y_pos_;
	dest_rect_.w = src_rect_.w * 2;
	dest_rect_.h = src_rect_.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer_, object_texture_, &src_rect_, &dest_rect_);
}
