#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <map.h>
#include <ideology.h>
#include <random>

class MapGenerator
{
public:
    int mapWidth;
    int mapHeight;
    int mapIdeologies;

    MapGenerator(int width=0, int height=0, int ideologyCount=0);
    Map generateNewMap();
};

#endif
