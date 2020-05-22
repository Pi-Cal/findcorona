#include "Monster.h"
#include "TextureManager.h"
#include "Map.h"
#include <SDL.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include "Game.h"
#include "Map.h"
Map* mapmap4;

int speedM = 2;

const int posX[]={0,0,speedM,-speedM};
const int posY[]={speedM,-speedM,0,0};



void Monster::tranfer(int & xpos, int & ypos,int i){
    xpos += posX[i];
    ypos += posY[i];
}

void Monster::checkM(int& xpos, int&ypos ,const int height1, const int width1){
    if (xpos < 0) xpos += speedM;
    if (ypos < 0) ypos += speedM;
    if (xpos+height1>=480) xpos -=speedM;
    if (ypos+width1>=480) ypos -=speedM;

}



std::vector< std::pair<int,int> > pos1;

void Monster::MonsterGen(int arr[][widthInArray2]){
    for (int i=1;i<heigtInArray2-1;i++)
        for (int j=1;j<widthInArray2-1;j++)
            if (arr[i][j]==0&&arr[i+1][j]==0&&arr[i][j+1]==0&&arr[i+1][j+1]==0)
                pos1.push_back(std::make_pair(j,i));
    int choose = SDL_GetTicks()%pos1.size();
    xpos = pos1[choose].first*convertPos;
    ypos = pos1[choose].second*convertPos;

}

Monster::Monster(const char* texturesheet,int i)
{
    monsterTexture = TextureManager::LoadTexture(texturesheet);
    mapmap4 = new Map();
    MonsterGen(mapmap4->map2);

    frameCount = 16;
    animateSpeed = 40;

    ran = i;

}
Monster::~Monster()
{

}

void Monster::Update()
{
    srcRect.h = 167;
    srcRect.w = 213;
    srcRect.x = 0;
    srcRect.y = 167*frame;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = 16*2-speedM;
    destRect.w = 16*2-speedM;

    frame = (SDL_GetTicks()/animateSpeed)%frameCount;
    tranfer(xpos,ypos,ran);
    checkM(xpos,ypos,destRect.h,destRect.w);
    if ((mapmap4->map2[ypos/heightM][xpos/widthM]!=0||mapmap4->map2[ypos/heightM][(xpos+destRect.w)/widthM]!=0)||
        (mapmap4->map2[(ypos+destRect.h)/heightM][xpos/widthM]!=0||mapmap4->map2[(ypos+destRect.h)/heightM][(xpos+destRect.w)/widthM]!=0)||
        (mapmap4->map2[ypos/heightM][xpos/widthM]!=0||mapmap4->map2[(ypos+destRect.h)/heightM][xpos/widthM]!=0)||
        (mapmap4->map2[ypos/heightM][(xpos+destRect.w)/widthM]!=0||mapmap4->map2[(ypos+destRect.h)/heightM][(xpos+destRect.w)/widthM]!=0)
        ){
        if (ran%2==0)
        ran++;
        else ran --;
    }


}

void Monster::Render()
{
    SDL_RenderCopy(Game::renderer, monsterTexture, &srcRect, &destRect);
}


void Monster::Clean()
{

}
