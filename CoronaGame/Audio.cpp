#include "Audio.h"
#include <iostream>


Audio::Audio(){}



void Audio::eatSound(){
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    sound = Mix_LoadWAV("sound/eatingsound2.wav");
    if(!sound) std::cout << "ErrorSound2" << Mix_GetError() <<   std::endl;
    else Mix_PlayChannel(-1,sound,0);
}

void Audio::SoundTrack(){
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    soundtrack = Mix_LoadMUS("sound/soundtrack.mp3");
    if(!soundtrack) std::cout << "Error SoundTrack" << std::endl;
    else Mix_PlayMusic(soundtrack,-1);
}
void Audio::Free()
{
    Mix_CloseAudio();
    Mix_FreeChunk(sound);
    Mix_FreeMusic(soundtrack);
}
