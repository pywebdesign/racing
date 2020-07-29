#ifndef KEYBOARD
#define KEYBOARD 

#include <iostream>
#include <chrono>
#include <SDL.h>
#include <map> 
#include "Keyboard.h"


class Keyboard
{
public:
    static Keyboard& getInstance();
private:
    Keyboard();                    // Constructor? (the {} brackets) are needed here.

    // C++ 03
    // ========
    // Don't forget to declare these two. You want to make sure they
    // are inaccessible(especially from outside), otherwise, you may accidentally get copies of
    // your singleton appearing.
    Keyboard(Keyboard const&)=delete;              // Don't Implement
    void operator=(Keyboard const&)=delete; // Don't implement
    std::map<SDL_Keycode, bool> pressed;
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    bool isPressed(SDL_KeyCode key);
    void handleEvents(SDL_Event& event);

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
};

#endif