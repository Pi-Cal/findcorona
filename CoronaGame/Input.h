#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>




class Input
{
    public:
        Input();
        static Input* GetInstace(){
            return instance = (instance != nullptr)? instance : new Input();
        }
        void Listen();
        bool GetKeyDown(SDL_Scancode key);

    private:
        void KeyUp();
        void KeyDown();
        const Uint8* VvKeyStates;
        static Input* instance;
};

#endif // INPUT_H
