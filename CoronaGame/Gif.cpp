#include "Gif.h"
#include "TextureManager.h"
#include <SDL.h>
#include "Game.h"



Gif::Gif(const char* texturesheet, int x, int y, int hei, int wid,int srcW, int srcH,int framecnt)
{
    gifTexture = TextureManager::LoadTexture(texturesheet);
    frameCount = framecnt;
    animateSpeed = 80;
    xpos = x;
    ypos = y;
    heightGif = hei;
    widthGif = wid;
    srcWid = srcW;
    srcHei = srcH;
}

Gif::~Gif()
{}

void Gif::Update()
{
    srcRect.h = srcHei;
    srcRect.w = srcWid;
    srcRect.x = 0;
    srcRect.y = srcHei*frame;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = heightGif;
    destRect.w = widthGif;

    frame = (SDL_GetTicks()/animateSpeed)%frameCount;
}

void Gif::Render()
{
    SDL_RenderCopy(Game::renderer, gifTexture, &srcRect, &destRect);
}
