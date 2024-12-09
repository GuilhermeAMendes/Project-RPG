#include "Battle.h"
#include <stdio.h>

void battle(Character *player, Region *region)
{
    int initialHealthPointsEnemy = region->enemy->heathPoints;
    while (isAlive(player) && isAlive(region->enemy))
    {
        printf("\n➡️ Turno do jogador: **%s**\n", player->name);
        attack(player, region->enemy);

        if (!isAlive(region->enemy))
        {
            printf("\n🎉 %s derrotou o inimigo **%s**!\n", player->name, region->enemy->name);
            region->enemy->heathPoints = 0;

            upgradeStatus(player);
            showStatus(player);
            region->enemy->heathPoints = initialHealthPointsEnemy;
            break;
        }

        printf("\n⚠️ Turno do inimigo: **%s**\n", region->enemy->name);
        attack(region->enemy, player);

        if (!isAlive(player))
        {
            printf("\n💀 %s foi derrotado por **%s**...\n", player->name, region->enemy->name);
            printPath(region);
            break;
        }
    }
}