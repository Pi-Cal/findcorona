#include "GameObjects.h"
#include "TextureManager.h"
#include <SDL.h>
#include "Input.h"
#include "Map.h"
#include <iostream>
#include <SDL.h>

const int heigt=16, width=16;

int speed = 3;

const int posX[]={0,0,speed,-speed};
const int posY[]={speed,-speed,0,0};


Map *mapmap2;



void tranlate(int & xpos, int & ypos,int i){
    xpos += posX[i];
    ypos += posY[i];
}


void check(int& xpos, int&ypos ,const int height1, const int width1){
    if (xpos < 0) xpos += speed;
    if (ypos < 0) ypos += speed;
    if (xpos+height1>=1040) xpos -=speed;
    if (ypos+width1>=1008) ypos -=speed;

}


GameObjects::GameObjects(const char* texturesheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;

    frameCount = 2;
    animateSpeed = 60;

}

void GameObjects::Update()
{
    mapmap2 = new Map();
    check(xpos,ypos,destRect.h,destRect.w);
    srcRect.h = 2065;
    srcRect.w = 1691;
    srcRect.x = 1691*frame;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = 16*2-speed;
    destRect.w = 16*2-speed;

    frame = (SDL_GetTicks()/animateSpeed)%frameCount;

    if (Input::GetInstace()->GetKeyDown(SDL_SCANCODE_W)){
        tranlate(xpos,ypos,1);
        check(xpos,ypos,destRect.h,destRect.w);
        if (mapmap2->map2[ypos/heigt][xpos/width]!=0||mapmap2->map2[ypos/heigt][(xpos+destRect.w)/width]!=0)
            tranlate(xpos,ypos,0);

    }
    if (Input::GetInstace()->GetKeyDown(SDL_SCANCODE_S)){
        tranlate(xpos,ypos,0);
        check(xpos,ypos,destRect.h,destRect.w);
        if (mapmap2->map2[(ypos+destRect.h)/heigt][xpos/width]!=0||mapmap2->map2[(ypos+destRect.h)/heigt][(xpos+destRect.w)/width]!=0)
            tranlate(xpos,ypos,1);
    }
    if (Input::GetInstace()->GetKeyDown(SDL_SCANCODE_A)){
        tranlate(xpos,ypos,3);
        check(xpos,ypos,destRect.h,destRect.w);
        if (mapmap2->map2[ypos/heigt][xpos/width]!=0||mapmap2->map2[(ypos+destRect.h)/heigt][xpos/width]!=0)
            tranlate(xpos,ypos,2);
    }
    if (Input::GetInstace()->GetKeyDown(SDL_SCANCODE_D)){
        tranlate(xpos,ypos,2);
        check(xpos,ypos,destRect.h,destRect.w);
        if (mapmap2->map2[ypos/heigt][(xpos+destRect.w)/width]!=0||mapmap2->map2[(ypos+destRect.h)/heigt][(xpos+destRect.w)/width]!=0)
            tranlate(xpos,ypos,3);

    }


}

void GameObjects::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
