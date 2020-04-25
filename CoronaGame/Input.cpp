#include "Input.h"
#include "SDL.h"
#include <iostream>
#include "Game.h"
#include "Menu.h"



Input* Input::instance = nullptr;


Input::Input(){
    VvKeyStates = SDL_GetKeyboardState(nullptr);
}
void Input::Listen()
{
    SDL_Event event;

    while(SDL_PollEvent(& event)){
        switch(event.type){
            case SDL_KEYDOWN: KeyDown(); break;
            case SDL_KEYUP: KeyUp(); break;
            case SDL_QUIT:
                Game::GetInstance()->quit();
                Menu::GetInstance()->Quit();
                Menu::GetInstance()->GameEnd();
                break;
            default:
                break;
            }
    }
}

bool Input::GetKeyDown(SDL_Scancode key)
{
    if (VvKeyStates[key] == 1) return true;
    return false;
}

void Input::KeyUp()
{
    VvKeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown()
{
    VvKeyStates = SDL_GetKeyboardState(nullptr);
}
