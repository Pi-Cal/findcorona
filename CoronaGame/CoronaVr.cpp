#include "CoronaVr.h"
#include "TextureManager.h"
#include "Map.h"
#include <SDL.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include "Game.h"


Map* mapmap3;



std::vector< std::pair<int,int> > pos0;

void Virus::VirusGen(int arr[][widthInArray1]){
    for (int i=1;i<heigtInArray1-1;i++)
        for (int j=1;j<widthInArray1-1;j++)
            if (arr[i][j]==0&&arr[i+1][j]==0&&arr[i][j+1]==0&&arr[i+1][j+1]==0)
                pos0.push_back(std::make_pair(j,i));
    int choose = SDL_GetTicks()%pos0.size();
    xpos = pos0[choose].first*convertPos1;
    ypos = pos0[choose].second*convertPos1;

}

Virus::Virus(const char* texturesheet)
{
    virusTexture = TextureManager::LoadTexture(texturesheet);
    mapmap3 = new Map();
    VirusGen(mapmap3->map2);

    frameCount = 4;
    animateSpeed = 80;

}

void Virus::Update()
{

    srcRect.h = heigtOfVirus;
    srcRect.w = heigtOfVirus;
    srcRect.x = widthOfVirus*frame;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h*2;
    destRect.w = srcRect.w*2;

    frame = (SDL_GetTicks()/animateSpeed)%frameCount;

}

void Virus::Render()
{
    SDL_RenderCopy(Game::renderer, virusTexture, &srcRect, &destRect);
}
void Virus::Clean(){

}
