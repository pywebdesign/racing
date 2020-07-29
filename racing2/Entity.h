#ifndef ENTITY
#define ENTITY 

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Keyboard.h"
#include "Entity.h"
namespace Entity {
class Entity
{
public:
	Entity();
	Entity(SDL_Renderer* renderer);
	~Entity();

	int h, w;
	double x, y, vx, vy, ax, ay, jx, jy;
	SDL_Texture* texture;
	SDL_Rect rect;
	
	virtual SDL_Texture* getSDL_Texture();
	virtual SDL_Rect* getSDL_Rect();
	virtual void update(double t);
};

	enum class EntityType {
		Player,
		Terrain,
		Camera,
		NPC,
		Enemy,
	};
}
#endif