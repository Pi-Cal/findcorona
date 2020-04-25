#ifndef VIRUSICON_H
#define VIRUSICON_H

#include <SDL.h>

#include "TextureManager.h"
#include <SDL.h>
#include "Game.h"


class VirusIcon
{
    public:
        VirusIcon(const char* texturesheet,int x, int y);
        ~VirusIcon();

        void Update();
        void Render();

        int xpos;
        int ypos;
        SDL_Rect srcRect, destRect;
    private:
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* objTexture;
};

#endif // VIRUSICON_H
