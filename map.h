#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <sstream>
#include <vector>
#include <random>

#include <windows.h>
#include <villager.h>

using namespace std;

class Map
{
public:
    int width;
    int height;
    vector< Villager* > villagers;

    Map(int mapWidth, int mapHeight, vector< Villager* > mapVillagers);
    void render();
    void tick();
};

#endif
