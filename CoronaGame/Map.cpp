#include "Map.h"
#include "TextureManager.h"
#include <fstream>
#include <vector>
#include <string>
#include <SDL.h>
#include "Game.h";

const int widthInArray = 63, heigtInArray = 63;

std::vector<std::string> hostFileArray;

int maplv1[heigtInArray][widthInArray];


Map::Map()
{
    road = TextureManager::LoadTexture("image/road.png");
    grass = TextureManager::LoadTexture("image/grass2.png");
    water = TextureManager::LoadTexture("image/water.png");

    std::string s1=chooseMap("map/fileHost.txt");

    loadMapFromFile(s1);

    LoadMap(maplv1);

    src.x = src.y = 0;
    src.w = dest.w = 16;
    src.h = dest.h = 16;

}

std::string Map::chooseMap(std::string hostmap){
    std::ifstream host(hostmap);
    if(host.is_open()){
        std::string s;
        while(host>>s)
            hostFileArray.push_back(s);
        return hostFileArray[0];

    }else std::cout << "Can't open Host File!" << std::endl;
}

void Map::loadMapFromFile(std::string fileName){
    std::ifstream file(fileName);
    if(file.is_open()){
        char x;
        if(file){
            for (int i=0;i<heigtInArray;i++)
                for (int j=0;j<widthInArray;j++){
                    file >> x;
                    maplv1[i][j]=(int)x-'0';
                }
        }
    }else std::cout << "Err";
}

void Map::LoadMap(int arr[heigtInArray][widthInArray])
{
    for (int row=0; row<heigtInArray; row++){
        for (int column = 0; column <widthInArray; column++){
            map1[row][column] = arr[row][column];
            map2[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;
    for (int row=0; row<heigtInArray; row++){
        for (int column =0; column <widthInArray; column++){
            type = map1[row][column];

            dest.x = column *16;
            dest.y = row * 16;

            switch(type){
            case 0:
                TextureManager::Draw(road, src, dest);
                break;
            case 1:
                TextureManager::Draw(grass, src, dest);
                break;
            case 2:
                TextureManager::Draw(water, src, dest);
                break;

            default:
                break;
            }
        }
    }
}
