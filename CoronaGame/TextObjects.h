#ifndef TEXTOBJECTS_H
#define TEXTOBJECTS_H


#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class TextObjects
{
    public:
        TextObjects();
        ~TextObjects();

        enum TextColor{
            BLUE_TEXT = 0,
            WHITE_TEXT = 1,
            RED_TEXT = 2,
        };

        bool LoadFromRenderText(TTF_Font* font);
        void Free();

        void SetColor(Uint8 red, Uint8 green, Uint8 blue);
        void SetColor(int type);

        void RenderText(int xpos, int ypos);
        int GetWidth() const {return widthText;}
        int GetHeigt() const {return heigtText;}

        void SetText(const std::string& text) {strVal = text;}
        std::string GetText() const {return strVal;}
    private:
        std::string strVal;
        SDL_Color textColor;
        SDL_Texture* texture;
        int widthText;
        int heigtText;
};

#endif // TEXTOBJECTS_H
