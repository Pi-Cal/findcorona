#include "Game.h"
#include <SDL_image.h>
#include <string>
#include "TextureManager.h"
#include "GameObjects.h"
#include "Map.h"
#include "Input.h"
#include "CoronaVr.h"
#include <SDL_mixer.h>
#include "TextObjects.h"
#include "Congraculation.h"
#include "VirusIcon.h"
#include "Menu.h"
#include "Audio.h"

Game *Game::instance = nullptr;

GameObjects* player1;

Map *mapmap = nullptr;

Audio *music;

VirusIcon* icon;

TTF_Font* fontTime = NULL;

TextObjects* timeGame;
TextObjects* NumOfVirus;


SDL_Renderer* Game::renderer = nullptr;


void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    // Tao man hinh window
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)==NULL)
    {
        std::cout << "Subsystem Initialised ..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer,150,150,200,0);
            std::cout << "Renderer create! " << std::endl;
        }
        isRunning = true;
    }

    // Tao nhan vat cho game
    player1 = new GameObjects("image/doctor2.png",0,0);
    //Sinh Virus
    genVirus();
    //Sinh Map
    mapmap = new Map;
    //Virus Count Icon
    music = new Audio();

    icon = new VirusIcon("image/countvirus2.png",360,12);

    if (TTF_Init()==-1){
        std::cout << "Can't load the Init " << TTF_GetError() << std::endl;
    }
    fontTime = TTF_OpenFont("Font/gamefont.ttf",17);

    timeGame = new TextObjects();

    NumOfVirus = new TextObjects();

    music->SoundTrack();

    Menu::GetInstance()->GetMenu();



}

void Game::genVirus(){
    virus1 = new Virus("image/boom2.png");
    virusDied = false ;
}


void Game::SetTime(){
    if (fontTime == NULL){
        std::cout << "ErrorTime: "<< TTF_GetError() << std::endl;
    }
    timeGame->SetColor(TextObjects::WHITE_TEXT);
    std::string strTime = "Time: ";
    Uint32 timeVal = SDL_GetTicks()/1000;
    int limitedTime = 30-timeVal;
    std::string strValue = std::to_string(limitedTime);
    strTime += strValue;
    timeGame->SetText(strTime);
    timeGame->LoadFromRenderText(fontTime);
    if (limitedTime==0) isPlaying = false ;

}

void Game::CountVirus(){
    if (fontTime == NULL){
        std::cout << "ErrorTime: "<< TTF_GetError() << std::endl;
    }
    timeGame->SetColor(TextObjects::WHITE_TEXT);
    std::string numVirus = std::to_string(score);
    NumOfVirus->SetText(numVirus);
    NumOfVirus->LoadFromRenderText(fontTime);
}

void Game::handleCollision(){
    if((player1->xpos<=virus1->xpos&&(player1->xpos+player1->destRect.w)>=virus1->xpos&&player1->ypos<=virus1->ypos&&(player1->ypos+player1->destRect.h)>=virus1->ypos)||
       (player1->xpos<=(virus1->xpos+virus1->destRect.w)&&(player1->xpos+player1->destRect.w)>=(virus1->xpos+virus1->destRect.w)&&
        player1->ypos<=virus1->ypos&&(player1->ypos+player1->destRect.h)>=virus1->ypos)||
       (player1->xpos<=virus1->xpos&&(player1->xpos+player1->destRect.w)>=virus1->xpos&&player1->ypos<=(virus1->ypos+virus1->destRect.h)&&
        (player1->ypos+player1->destRect.h)>=(virus1->ypos+virus1->destRect.h))||
       (player1->xpos<=(virus1->xpos+virus1->destRect.w)&&(player1->xpos+player1->destRect.w)>=(virus1->xpos+virus1->destRect.w)&&
        player1->ypos<=(virus1->ypos+virus1->destRect.h)&&(player1->ypos+player1->destRect.h)>=(virus1->ypos+virus1->destRect.h))
      )
        {
            virus1->isAlive=false;
            virusDied=true;
            music->eatSound();
            score++;
        }
}

void Game::handleEvents()
{
    if(IsPlaying()) Input::GetInstace()->Listen();
    else Menu::GetInstance()->menuHandleEvent();
}

void Game::update()
{
    player1 -> Update();
    icon -> Update();
    Menu::GetInstance()-> Update();
    if(virus1->alive())
        virus1 -> Update();

}

void Game::render()
{
    SDL_RenderClear(renderer);
    mapmap -> DrawMap();
    player1 -> Render();
    if(virus1 -> alive())
        virus1 -> Render();
    timeGame -> RenderText(568,12);
    icon -> Render();
    NumOfVirus->RenderText(390,14);
    if(!IsPlaying()) Menu::GetInstance() -> Render();
    SDL_RenderPresent(renderer);
}
void Game::quit(){
    isRunning=false;
}
void Game::GameContinue(){
    isPlaying = true;
    virusDied=false;
    isRunning = false;
    score = 0;
}
void Game::clean()
{
        music -> Free();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        std::cout <<"Your Score: "<< score << std::endl << "Game Cleaned " << std::endl;

}



