#include "villager.h"

Villager::Villager(int posX, int posY, Ideology* villagerIdeology)
{
    x = posX;
    y = posY;
    ideology = villagerIdeology;
}

int Villager::getPosX()
{
    return x;
}

int Villager::getPosY()
{
    return y;
}

Ideology* Villager::getIdeology()
{
    return ideology;
}

int Villager::getColor()
{
    int villagerColor = ideology->color;
    return villagerColor;
}

char Villager::getIcon()
{
    int villagerIcon = ideology->icon;
    return villagerIcon;
}

Villager* Villager::findConversationPartner(vector< Villager* > mapVillagers, int mapWidth, int mapHeight, int villagerIndex)
{
    random_device random_device;
    mt19937 engine{random_device()};

    uniform_int_distribution<int> directionOfTalking(1, 4);

    Villager* conversationVillager = mapVillagers[villagerIndex];
    int conversationPartnerIndex;

    switch (directionOfTalking(engine)) {
        // Bewohner oben drueber
        case 1:
            if (conversationVillager->y == 1) {
                return nullptr;
            }

            conversationPartnerIndex = villagerIndex - mapWidth;
        // Bewohner rechts nebenan
        case 2:
            if (conversationVillager->x == mapWidth) {
                return nullptr;
            }

            conversationPartnerIndex = villagerIndex + 1;
        // Bewohner unten drunter
        case 3:
            if (conversationVillager->y == mapHeight) {
                return nullptr;
            }

            conversationPartnerIndex = villagerIndex + mapWidth;
        // Bewohner links nebenan
        case 4:
            if (conversationVillager->x == 1) {
                return nullptr;
            }

            conversationPartnerIndex = villagerIndex - 1;
    }

    Villager* conversationPartner = mapVillagers[conversationPartnerIndex];
    return conversationPartner;
}

void Villager::haveConversation(Villager* conversationPartner)
{
    Ideology* ownIdeology = this->ideology;
    Ideology* foreignIdeology = conversationPartner->ideology;

    // Nur reden, wenn die Weltanschauung unterschiedlich ist
    if (ownIdeology->color != foreignIdeology->color) {
        random_device random_device;
        mt19937 engine{random_device()};

        uniform_int_distribution<int> probabilityOfConvincement(1, 100);

        // Chance auf Überzeugung: 50 zu 50
        if (probabilityOfConvincement(engine) <= 50) {
            foreignIdeology = ownIdeology;
        } else {
            ownIdeology = foreignIdeology;
        }
    }

    this->ideology = ownIdeology;
    conversationPartner->ideology = foreignIdeology;
}
