#ifndef MONSTER_H
#define MONSTER_H

#include <SDL.h>

const int widthInArray2 = 30, heigtInArray2=30, widthOfMonster=16, heigtOfMonster=16;
const int convertPos = 16;
const int heightM = 16, widthM = 16;


class Monster
{
    public:
        Monster(const char* texturesheet, int i);
        virtual ~Monster();
        void Update();
        void Render();
        void MonsterGen(int arr[][widthInArray2]);
        bool alive(){return isAlive;}
        void Clean();
        bool isAlive = true;
        int xpos;
        int ypos;
        void tranfer(int & xpos, int & ypos,int i);
        void checkM(int& xpos, int&ypos ,const int height1, const int width1);

        SDL_Rect srcRect, destRect;

    private:
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* monsterTexture;
        int ran;
};

#endif // MONSTER_H
