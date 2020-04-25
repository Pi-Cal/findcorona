#include "VirusIcon.h"

const int heigtIcon = 24, widthIcon=24;

VirusIcon::VirusIcon(const char* texturesheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos=x;
    ypos=y;

}


void VirusIcon::Update()
{
    srcRect.h = heigtIcon;
    srcRect.w = widthIcon;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
}

void VirusIcon::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
