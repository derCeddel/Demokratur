#include "ideology.h"

Ideology::Ideology(int ideologyColor, char ideologyIcon)
{
    if (ideologyColor < 1 || ideologyColor > 255) {
        ideologyColor = 1;
    }

    color = ideologyColor;

    icon = ideologyIcon;
}
