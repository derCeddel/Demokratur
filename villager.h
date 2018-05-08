#ifndef VILLAGER_H
#define VILLAGER_H

#include <vector>
#include <random>

#include <ideology.h>

using namespace std;

class Villager
{
public:
    int x;
    int y;
    Ideology* ideology;

    Villager(int posX, int posY, Ideology* villagerIdeology);

    int getPosX();
    int getPosY();
    Ideology* getIdeology();

    int getColor();
    char getIcon();
    Villager* findConversationPartner(vector< Villager* > mapVillagers, int mapWidth, int mapHeight, int villagerIndex);
    void haveConversation(Villager* conversationPartner);
};

#endif
