#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include "TextObjects.h"

class Menu
{
    public:
        Menu();

        static Menu *GetInstance(){
            return instance = (instance!=nullptr)? instance: new Menu();
        }
        void Update();
        void Render();
        void menuHandleEvent();
        bool play(){ return playAgain; }
        bool GameEnd(){ return playAgain; }
        void Quit() {playAgain = false;}
        void GetMenu();
        void Reset(){instance = nullptr;}

    private:
        int xpos, ypos;
        SDL_Texture* menuTexture;
        SDL_Rect srcRec, desRect;
        TextObjects* menuTextYes;
        TextObjects* menuTextNo;
        TextObjects* scoreFinal;
        int scoreFinalInt;
        std::string strMenuYes, strMenuNo, strScore;
        bool playAgain = true ;

        static Menu *instance;
};

#endif // MENU_H
