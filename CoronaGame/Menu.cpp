#include "Menu.h"
#include "TextureManager.h"
#include "TextObjects.h"
#include "Game.h"
#include "Input.h"


TTF_Font* fontMenu = NULL;

Menu* Menu::instance = nullptr;

Menu::Menu()
{

}

void Menu::GetMenu(){
    menuTexture = TextureManager::LoadTexture("image/menugame.png");
    if (TTF_Init()==-1){
        std::cout << "Can't load the Init " << TTF_GetError() << std::endl;
    }

    fontMenu = TTF_OpenFont("Font/gamefont.ttf",20);
    menuTextYes = new TextObjects();
    strMenuYes = "YES";
    menuTextYes -> SetColor(TextObjects::WHITE_TEXT);
    menuTextNo = new TextObjects();
    strMenuNo = "NO";

}

void Menu::menuHandleEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(& event)){
        switch(event.type){
            case SDL_MOUSEMOTION:
                {
                    xpos = (int) event.motion.x;
                    ypos = (int) event.motion.y;
                    if ((xpos>=410&&ypos>=550)&&(xpos<=495&&ypos<=585)){
                        menuTextYes -> SetColor(TextObjects::RED_TEXT);
                        playAgain = true;
                    }
                    else menuTextYes -> SetColor(TextObjects::WHITE_TEXT);
                    if ((xpos>=520&&ypos>=550)&&(xpos<=605&&ypos<=585)){
                        menuTextNo -> SetColor(TextObjects::RED_TEXT);
                        playAgain = false;
                    }
                    else menuTextNo -> SetColor(TextObjects::WHITE_TEXT);

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                {
                    if((xpos>=410&&ypos>=550)&&(xpos<=495&&ypos<=585)){
                        //Game::GetInstance()->GameContinue();
                        std::cout<<"Yes \n";
                        Game::GetInstance()->quit();
                        GameEnd();
                    }
                    else if((xpos>=520&&ypos>=550)&&(xpos<=605&&ypos<=585)){
                        std::cout<<"No \n";
                        Game::GetInstance()->quit();
                        GameEnd();
                    }
                }
                break;
            case SDL_QUIT:
                Game::GetInstance()->quit();
                std::cout << "Out khong co duoc! \n";
                playAgain = false;
                GameEnd();
                break;
            default:
                break;
            }
    }
}

void Menu::Update()
{
    menuHandleEvent();
    menuTextYes -> SetText(strMenuYes);
    menuTextYes -> LoadFromRenderText(fontMenu);
    menuTextNo -> SetText(strMenuNo);
    menuTextNo -> LoadFromRenderText(fontMenu);
    desRect.x=120;
    desRect.y=280;
    desRect.w=800;
    desRect.h=480;
}

void Menu::Render()
{
    SDL_RenderCopy(Game::renderer, menuTexture,  NULL, &desRect );
    menuTextYes -> RenderText(423,564);
    menuTextNo -> RenderText(540,564);
}
