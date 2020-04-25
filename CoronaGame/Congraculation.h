#ifndef CONGRACULATION_H
#define CONGRACULATION_H

#include "TextureManager.h"
#include <SDL.h>
#include "Game.h"


class Congraculation
{
    public:
        Congraculation(const char* texturesheet);
        ~Congraculation();

        void Update(int x, int y);
        void Render();

        int xpos;
        int ypos;
        SDL_Rect srcRect, destRect;
    private:
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* objTexture;
};

#endif // CONGRACULATION_H
