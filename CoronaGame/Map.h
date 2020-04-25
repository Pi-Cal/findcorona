#ifndef MAP_H
#define MAP_H

#include <string>
#include <SDL.h>
class Map
{
    public:
        Map();
        ~Map();
    void LoadMap(int arr[65][65]);
    void DrawMap();
    int map2[65][65];
    void loadMapFromFile(std::string fileName);
    std::string chooseMap(std::string hostmap);

    int i=0;
    private:
        SDL_Rect src, dest;
        SDL_Texture* road;
        SDL_Texture* grass;
        SDL_Texture* water;

        int map1[65][65];
};

#endif // MAP_H
