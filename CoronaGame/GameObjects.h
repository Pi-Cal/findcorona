#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include <SDL.h>
#include "Game.h"

class GameObjects
{
    public:
        GameObjects(const char* texturesheet, int x, int y);
        ~GameObjects();

        void Update();
        void Render();


    public:
        int xpos;
        int ypos;
        SDL_Rect srcRect, destRect;
    private:
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* objTexture;
};

#endif // GAMEOBJECTS_H
