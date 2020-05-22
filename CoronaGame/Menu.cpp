#include "Menu.h"
#include "TextureManager.h"
#include "TextObjects.h"
#include "Game.h"
#include "Input.h"
#include "Gif.h"


TTF_Font* fontMenu = NULL;
TTF_Font* fontScore = NULL;

Gif *frameScore;

Menu* Menu::instance = nullptr;

Menu::Menu()
{

}

void Menu::GetMenu(){
    menuTexture = TextureManager::LoadTexture("image/menugame.png");
    if (TTF_Init()==-1){
        std::cout << "Can't load the Init " << TTF_GetError() << std::endl;
    }

    fontMenu = TTF_OpenFont("Font/gamefont.ttf",12);
    fontScore = TTF_OpenFont("Font/gamefont.ttf",22);
    menuTextYes = new TextObjects();
    strMenuYes = "YES";
    menuTextYes -> SetColor(TextObjects::WHITE_TEXT);
    menuTextNo = new TextObjects();
    strMenuNo = "NO";
    scoreFinal = new TextObjects();

    frameScore = new Gif("image/frame.png",262,290,58,70,219,76,6);

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
                    if ((xpos>=188&&ypos>=262)&&(xpos<=227&&ypos<=289)){
                        menuTextYes -> SetColor(TextObjects::RED_TEXT);
                        playAgain = true;
                    }
                    else menuTextYes -> SetColor(TextObjects::WHITE_TEXT);
                    if ((xpos>=240&&ypos>=261)&&(xpos<=282&&ypos<=289)){
                        menuTextNo -> SetColor(TextObjects::RED_TEXT);
                        playAgain = false;
                    }
                    else menuTextNo -> SetColor(TextObjects::WHITE_TEXT);

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                {
                    if((xpos>=188&&ypos>=262)&&(xpos<=227&&ypos<=289)){
                        //Game::GetInstance()->GameContinue();
                        std::cout<<"Yes \n";
                        Game::GetInstance()->quit();
                        GameEnd();
                    }
                    else if((xpos>=240&&ypos>=261)&&(xpos<=282&&ypos<=289)){
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
    scoreFinal -> SetText(strScore);
    scoreFinal -> SetColor(TextObjects::WHITE_TEXT);
    scoreFinal -> LoadFromRenderText(fontScore);
    desRect.x=40;
    desRect.y=100;
    desRect.w=400;
    desRect.h=280;

    scoreFinalInt = Game::GetInstance()->GetScore();
    strScore = std::to_string(scoreFinalInt);

    frameScore -> Update();
}

void Menu::Render()
{
    SDL_RenderCopy(Game::renderer, menuTexture,  NULL, &desRect );
    menuTextYes -> RenderText(188,264);
    menuTextNo -> RenderText(250,264);
    frameScore -> Render();
    scoreFinal -> RenderText (277,307);
}
