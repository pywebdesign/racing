#include "Entity.h"

Entity::Entity::Entity()
{
}
Entity::Entity::Entity(SDL_Renderer* renderer) {}

Entity::Entity::~Entity(){}

SDL_Texture* Entity::Entity::getSDL_Texture()
{
	return texture;
}

SDL_Rect* Entity::Entity::getSDL_Rect()
{
	rect.x = int(x);
	rect.y = int(y);
	rect.h = int(h);
	rect.w = int(w);
	return &rect;
}


void Entity::Entity::update(double t)
{
}


