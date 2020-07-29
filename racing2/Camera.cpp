#include "Camera.h"


Camera::Camera(SDL_Renderer* renderer, int width, int height)
{
	// shoudl be calc centered in window
	x = 0;
	y = 0;
	h = width;
	w = height;
}

Camera::~Camera()
{}

void Camera::follow(std::shared_ptr <Entity> followed, int offsetX, int offsetY)
{
	// TODO:  there is some method to asing before body, it may be usefull, I dont remember exactly what it does
	this->followed = followed;
	this->offsetX = offsetX/2;
	this->offsetY = offsetY/2;
}



void Camera::update(double t) 
{
	x = followed->x - offsetX - h/2;
	y = followed->y - offsetY - h/2;
	std::cout << "camera " << x << " " << y << "\n";
}

void Camera::getRenderPosition(std::shared_ptr<Entity> entity, SDL_Rect* r)
{
	r->x = entity->getSDL_Rect()->x - x;
	r->y = entity->getSDL_Rect()->y - y;
	r->h = entity->getSDL_Rect()->h;
	r->w = entity->getSDL_Rect()->w;
}
