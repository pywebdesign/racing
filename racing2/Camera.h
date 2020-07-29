#ifndef CAMERA
#define CAMERA 
#include "Entity.h"
#include <memory>

class Camera : public Entity::Entity
{
public:
	Camera(SDL_Renderer* renderer, int width, int height);
	~Camera();
	void follow(std::shared_ptr <Entity> followed, int offsetX, int offsetY);
	void update(double t);
	void getRenderPosition(std::shared_ptr<Entity> entity, SDL_Rect* r);
private:
	std::shared_ptr <Entity> followed;
	int offsetX, offsetY;
	//SDL_Rect* getSDL_Rect();
};

#endif