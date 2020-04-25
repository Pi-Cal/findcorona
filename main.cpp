#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <windows.h>
#include "CoronaGame/Game.h"
#include <SDL_image.h>
#include "CoronaGame/TextureManager.h"
#include "Menu.h"
#include "Audio.h"


using namespace std;


void choiDiAe(){
    const int FPS = 60;
    const int frameDelay=1000/FPS;

    Uint32 frameStart;
    int frameTime;

    Game::GetInstance() -> init("CoronaVr", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1040,1040,false);
    while (Game::GetInstance()->running()){

        frameStart = SDL_GetTicks();

        if(Game::GetInstance()->IsPlaying()&&Game::GetInstance()->VirusDied())
            Game::GetInstance()->genVirus();
        if(Game::GetInstance()->IsPlaying()) {
            Game::GetInstance()->SetTime();
            Game::GetInstance()->CountVirus();
            Game::GetInstance()->handleCollision();
        }
        Game::GetInstance()->handleEvents();
        Game::GetInstance()->update();
        Game::GetInstance()-> render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay>frameTime){ SDL_Delay(frameDelay-frameTime); }
    }
    Game::GetInstance()->clean();
    Game::GetInstance()->Reset();
    Menu::GetInstance()->GameEnd();
}

int main()
{
    while (Menu::GetInstance()->play()&&Menu::GetInstance()->GameEnd())
        choiDiAe();

    return 0;
}
