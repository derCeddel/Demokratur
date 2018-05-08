#include "map.h"

Map::Map(int mapWidth, int mapHeight, vector< Villager* > mapVillagers)
{
    width = mapWidth;
    height = mapHeight;
    villagers = mapVillagers;
}

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void Map::render()
{
    system("cls");

    int renderedVillagerIndex = 0;

    for (int row = 1; row <= height; row++) {
        for (int col = 1; col <= width; col++) {
            Villager* renderedVillager = villagers[renderedVillagerIndex];

            stringstream iconStream;
            string villagerIcon;

            iconStream << renderedVillager->getIcon();
            iconStream >> villagerIcon;

            SetConsoleTextAttribute(consoleHandle, renderedVillager->getColor());
            cout << villagerIcon;

            renderedVillagerIndex++;
        }

        cout << endl;
    }

    SetConsoleTextAttribute(consoleHandle, 15);
}

void Map::tick()
{
    random_device random_device;
    mt19937 engine{random_device()};

    uniform_int_distribution<int> randomVillagerIndex(0, villagers.size() - 1);
    Villager* randomVillager = villagers[randomVillagerIndex(engine)];

    Villager* randomConversationVillager = randomVillager->findConversationPartner(this->villagers, this->width, this->height, randomVillagerIndex(engine));

    if (randomConversationVillager != nullptr) {
        randomVillager->haveConversation(randomConversationVillager);
    }
}
