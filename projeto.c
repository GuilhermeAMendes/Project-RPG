#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Character.c"
#include "Region.c"
#include "Battle.c"
#include "Game.c"

int main()
{
    srand(time(NULL));

    Character *player = createCharacter("Hero", 50, 15, 5);

    Character bestiary[14] = {
    {"Goblin", 50, 10, 5, 0},
    {"Skeleton", 45, 10, 5, 0},
    {"Mimic", 15, 10, 10, 0},
    {"Spyder", 40, 15, 10, 0},
    {"Copycat", 50, 15, 5, 0},
    {"Mimic", 20, 15, 10, 0},
    {"Troll", 90, 20, 15, 0},
    {"Dragon", 150, 30, 5, 0},
    {"Witch", 70, 10, 10, 0},
    {"Vampire", 65, 20, 5, 0},
    {"Stone Golem", 100, 12, 20, 0},
    {"Chimera", 90, 20, 11, 0},
    {"Lich", 85, 20, 10, 0},
    {"Hydra", 100, 15, 10, 0}
};


    Region *currentRegion = createRegion("Aldeia", &bestiary[0]);

    createRegions(currentRegion, bestiary, 14, 5);

    startGame(player, currentRegion);

    return 0;
}
