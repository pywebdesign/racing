#include <SDL.h>
#include <iostream>
#include "Window.h"

Window::Window(int width, int height) {
    this->quitted = false;
	SDL_Window* window = SDL_CreateWindow("Racer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
										   width, height, SDL_WINDOW_SHOWN);
    

	if (window == NULL)
	{
		std::cout << ("Window could not be created! SDL_Error: %s\n", SDL_GetError());

	}
}

void Window::PollEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
        switch (event.type) {
        case SDL_QUIT:
            quitted = true;
        case SDL_KEYDOWN:
            printf("Key press detected\n");
            break;

        case SDL_KEYUP:
            printf("Key release detected\n");
            break;

        default:
            break;
        }
    }
}

void Window::addPlayer(SDL_Surface* surface)
{
    playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Window::update()
{
    //Clear screen
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTexture, NULL, NULL);
    //Update screen
    SDL_RenderPresent(renderer);
}

