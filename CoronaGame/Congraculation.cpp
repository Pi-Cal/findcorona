#include "Congraculation.h"


const int heigtF=11, widthF=16;

Congraculation::Congraculation(const char* texturesheet)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
}


void Congraculation::Update(int x, int y)
{
    srcRect.h = heigtF;
    srcRect.w = widthF;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = x;
    destRect.y = y;
    destRect.h = srcRect.h*2;
    destRect.w = srcRect.w*2;
}

void Congraculation::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
