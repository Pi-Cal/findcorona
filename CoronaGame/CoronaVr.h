#ifndef VIRUS_H
#define VIRUS_H

#include <SDL.h>


const int widthInArray1 = 30, heigtInArray1=30, widthOfVirus=14, heigtOfVirus=14;
const int convertPos1 = 16;


class Virus
{
    public:
        Virus(const char* texturesheet);
        ~Virus();

        void Update();
        void Render();
        void VirusGen(int arr[][widthInArray1]);
        bool alive(){return isAlive;}
        void Clean();
    public:
        bool isAlive = true;
        int xpos;
        int ypos;

        SDL_Rect srcRect, destRect;
    private:
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* virusTexture;
};

#endif // VIRUS_H
