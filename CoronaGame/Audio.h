#ifndef AUDIO_H
#define AUDIO_H

#include <SDL_mixer.h>

class Audio
{
    public:
        Audio();
        void eatSound();
        void SoundTrack();
        void Free();
    private:
        Mix_Music *soundtrack = NULL;
        Mix_Chunk *sound = NULL;
};

#endif // AUDIO_H
