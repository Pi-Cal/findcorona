#include "TextObjects.h"
#include "Game.h"


TextObjects::TextObjects()
{
    textColor.r=255;
    textColor.b=255;
    textColor.g=255;
    texture = NULL;
}


bool TextObjects::LoadFromRenderText(TTF_Font* font)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, strVal.c_str(), textColor);
    if (textSurface){
        texture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
        widthText = textSurface->w;
        heigtText = textSurface->h;

        SDL_FreeSurface(textSurface);
        return texture != NULL;
    }
}

void TextObjects::Free()
{
    if (texture!=NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void TextObjects::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    textColor.r=red;
    textColor.g=green;
    textColor.b=blue;
}

void TextObjects::SetColor(int type){
    if (type == BLUE_TEXT){
        SDL_Color color = {135,206,235};
        textColor = color;
    }
    else if (type == WHITE_TEXT){
        SDL_Color color = {255,250,240};
        textColor = color;
    }
    else if (type == RED_TEXT){
        SDL_Color color = {255,1,0};
        textColor = color;
    }

}

void TextObjects::RenderText(int xpos, int ypos)
{
    SDL_Rect renderQuad = {xpos, ypos, widthText, heigtText};
    SDL_RenderCopy(Game::renderer, texture, NULL, &renderQuad);
}
