#ifndef GIF_H
#define GIF_H

#include <SDL.h>

class Gif
{
    public:
        Gif(const char* texturesheet, int x, int y, int hei, int wid,int srcW, int srcH,int framecnt);
        virtual ~Gif();
        void Update();
        void Render();

    private:
        SDL_Rect srcRect, destRect;
        int row, frame , frameCount;
        int animateSpeed;
        SDL_Texture* gifTexture;
        int xpos, ypos, widthGif, heightGif, srcWid, srcHei;
};

#endif // GIF_H
