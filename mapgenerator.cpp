#include "mapgenerator.h"

MapGenerator::MapGenerator(int width, int height, int ideologyCount)
{
    mapWidth = width;
    mapHeight = height;
    mapIdeologies = ideologyCount;
}

Map MapGenerator::generateNewMap()
{
    random_device random_device;
    mt19937 engine{random_device()};

    int ideologyColorNumber = 2;
    vector< Ideology* > newMapIdeologies;

    for (int ideology = 1; ideology <= mapIdeologies; ideology++) {
        Ideology* newIdeology = new Ideology(ideologyColorNumber);
        newMapIdeologies.push_back(newIdeology);

        ideologyColorNumber++;
    }

    uniform_int_distribution<int> ideologyIndex(0, newMapIdeologies.size() - 1);

    vector<Villager*> newMapVillagers;

    for (int row = 1; row <= mapHeight; row++) {
        for (int col = 1; col <= mapWidth; col++) {
            int randomIdeology = ideologyIndex(engine);
            Ideology* newVillagerIdeology = newMapIdeologies[randomIdeology];

            Villager* newVillager = new Villager(col, row, newVillagerIdeology);
            newMapVillagers.push_back(newVillager);
        }
    }

    Map newMap = Map(mapWidth, mapHeight, newMapVillagers);

    return newMap;
}
