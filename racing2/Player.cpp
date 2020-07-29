#include "Player.h"


double max_ax = 0.22;
double max_ay = 0.25;



Player::Player(SDL_Renderer* renderer) 
{
	// shoudl be calc centered in window
	x = 300;
	y = 300;
	h = 64;
	w = 64;
	SDL_Surface* roadSurface = IMG_Load("assets\\Car.png");
	texture = SDL_CreateTextureFromSurface(renderer, roadSurface);
}

Player::~Player()
{}

void Player::update(double t)
{
	if (Keyboard::getInstance().isPressed(SDLK_UP)) {
		jy = -1;
	}
	else if (Keyboard::getInstance().isPressed(SDLK_DOWN)) {
		jy = 1;
	}
	else
	{
		jy = 0;
		ay = 0;
	}
	if (Keyboard::getInstance().isPressed(SDLK_LEFT)) {
		jx = -1;
	}
	else if (Keyboard::getInstance().isPressed(SDLK_RIGHT)) {
		jx = 1;
	}
	else
	{
		jx = 0;
		ax = 0;
	}
	ax = ax + jx / 5 * t;
	ay = ay + jy / 300 * t;

	// cap at max_ax, max_ay with right sign
	if (std::abs(ax) > max_ax) {
		ax = (ax / std::abs(ax)) * max_ax;
	}
	if (std::abs(ay) > max_ay) {
		ay = (ay / std::abs(ay)) * max_ay;
	}

	vx = 0.9998 * vx + ax * t;
	vy = 0.9985 * vy + ay * t;

	// dynamic friction (cause it feels good)
	if (jx == 0) {
		vx *= 0.992;
	}
	if (jy == 0) {
		vy *= 0.9995;
	}
	x += vx * t;
	y += vy * t;
	std::cout << "player " << x << " " << y << "\n";
}
