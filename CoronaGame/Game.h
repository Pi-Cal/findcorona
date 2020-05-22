#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include <iostream>
#include "CoronaVr.h"
#include <SDL_mixer.h>
#include "Menu.h"


class Game
{
    public:
        static Game *GetInstance(){
            return instance =  (instance != nullptr)? instance:new Game();
        }
        void init(const char* title , int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void handleCollision();
        void handleCollision2();
        void update();
        void render();
        void clean();
        void quit();

        bool running(){return isRunning;}

        void genVirus();
        void genMonster();
        static SDL_Renderer *renderer;
        bool IsPlaying(){return isPlaying;}
        bool VirusDied(){return virusDied;}
        void GameContinue();
        void SetTime();
        void CountVirus();
        void Reset(){instance = nullptr;}
        int GetScore() {return score;}

    private:
        int score=0;
        bool isRunning = false, isPlaying=true,virusDied=false;
        SDL_Window *window;
        static Game *instance;
        int monsterCount = 0;
};

#endif // GAME_H
