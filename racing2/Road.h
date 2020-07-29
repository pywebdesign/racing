#ifndef ROAD
#define ROAD 

#include "SDL.h"
#include <iostream>
#include "Keyboard.h"
#include <SDL_image.h>
#include "Entity.h"

class Road : public Entity::Entity
{
public:
	Road(SDL_Renderer* renderer);
	~Road();
	void update(double t);
	SDL_Rect* getSDL_Rect();
	/*int h, w;
	double x, y, vx, vy, ax, ay, jx, jy;*/
};
#endif