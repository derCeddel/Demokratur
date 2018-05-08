#include "main.h"

MapGenerator *mapGenerator;

int updateSpeed;
clock_t lastUpdate = clock();
clock_t now;

bool isNextUpdate();
Map initialize();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool isRunning = true;

    Map map = initialize();

    while (isRunning) {
        map.tick();

        now = clock();

        if (isNextUpdate()) {
            map.render();

            lastUpdate = clock();
        } else {
            Sleep(100);
        }
    }

    return 0;
}

bool isNextUpdate()
{
    if ((now - lastUpdate) > 100 / updateSpeed) {
        return true;
    }

    return false;
}

Map initialize()
{
    cout << "Willkommen bei DEMOKRATUR!" << endl << endl;

    int mapWidth;

    cout << "Welche Breite soll die Spielwelt haben?" << endl;
    cin >> mapWidth;

    int mapHeight;

    cout << "Welche Höhe soll die Spielwelt haben?" << endl;
    cin >> mapHeight;

    int ideologyCount;

    cout << "Wie viele Ideologien soll es in der Spielwelt geben?" << endl;
    cin >> ideologyCount;

    if (ideologyCount > 5) {
        ideologyCount = 5;
    }

    cout << "Wie schnell soll die Simulation ablaufen (max. Stufe 3)?" << endl;
    cin >> updateSpeed;

    if (updateSpeed < 1) {
        updateSpeed = 1;
    } else if (updateSpeed > 3) {
        updateSpeed = 3;
    }

    mapGenerator = new MapGenerator(mapWidth, mapHeight, ideologyCount);
    Map generatedMap = mapGenerator->generateNewMap();

    delete mapGenerator;

    return generatedMap;
}
