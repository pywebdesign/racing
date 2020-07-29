#pragma once
#include <SDL.h>

class Window {
public:
	Window(int width, int height);
	void PollEvent();
	bool quitted;
	void addPlayer(SDL_Surface* surface);
	void update();
	SDL_Renderer* renderer = NULL;
	SDL_Texture* playerTexture;
};

