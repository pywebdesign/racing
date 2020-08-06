#include "Road.h"



Road::Road(SDL_Renderer* renderer)
{

	// Hardcoded, should be calc from road definition
	x = 0;
	h = 10000;
	w = 1200;
	y = -h/2;
	SDL_Surface* s = IMG_Load("assets\\road1.png");
	texture = SDL_CreateTextureFromSurface(renderer, s);
}

Road::~Road()
{}

void Road::update(double t) {
	
}

SDL_Rect* Road::getSDL_Rect()
{
	rect.x = int(x);
	rect.y = int(y);
	rect.h = int(h) ;
	rect.w = int(w);
	return &rect;
}

