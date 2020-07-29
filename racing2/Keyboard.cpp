#include "Keyboard.h"

/*Singleton pattern for keyboard
/ https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
*/

 Keyboard& Keyboard::getInstance()
    {
        static Keyboard    instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return instance;
    }
Keyboard::Keyboard() {
    std::cout << "Keyboard state manager instance created.\n";
}                   

void Keyboard::handleEvents(SDL_Event& event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
		pressed[event.key.keysym.sym] = true;
		break;
    case SDL_KEYUP:
        pressed[event.key.keysym.sym] = false;
        break;
    }
}
bool Keyboard::isPressed(SDL_KeyCode key)
{
	auto elem = pressed.find(key);
	if (elem != pressed.end()) {
		return pressed.at(key);
	}
	else {
		return false;
	}
}