#ifndef GAME
#define GAME 

#include <iostream>
#include <chrono>
#include <SDL.h>
#include <memory>
#include <map>
#include "Road.h"
#include "Player.h"
#include "Keyboard.h"
#include "Camera.h"
#include "EntityManager.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update(std::chrono::microseconds  delta);
	bool running() { return isRunning; }
	void render();
	void clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect roadRect;

	bool isRunning = false;
	int cnt = 0;
	float x, y;

};

#endif 
