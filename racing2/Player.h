#ifndef PLAYER
#define PLAYER 
#include "Entity.h"

class Player : public Entity::Entity
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
	void update(double t);
	//SDL_Rect* getSDL_Rect();
};

#endif