#include "Region.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

Region *createRegion(char *regionName, Character *enemy)
{
    Region *newRegion = (Region *)malloc(sizeof(Region));
    strcpy(newRegion->regionName, regionName);
    newRegion->enemy = enemy;
    newRegion->right = NULL;
    newRegion->left = NULL;
    newRegion->lastRegion = NULL;
    return newRegion;
}

void createRegions(Region *parent, Character *enemyList, int numEnemies, int maxDepth)
{
    if (maxDepth <= 0)
        return;

    Character *enemy1 = randomEnemy(enemyList, numEnemies);
    Region *region1 = createRegion("Floresta", enemy1);
    region1->lastRegion = parent;
    parent->left = region1;

    Character *enemy2 = randomEnemy(enemyList, numEnemies);
    Region *region2 = createRegion("Montanhas", enemy2);
    region2->lastRegion = parent;
    parent->right = region2;

    createRegions(region1, enemyList, numEnemies, maxDepth - 1);
    createRegions(region2, enemyList, numEnemies, maxDepth - 1);
}

Character *randomEnemy(Character *listEnemies, int numEnemies)
{
    if (numEnemies <= 0)
    {
        printf("Nenhum inimigo disponível.\n");
        return NULL;
    }

    int randomIndex = rand() % numEnemies;
    return &listEnemies[randomIndex];
}

void printPath(Region *currentRegion)
{
    if (currentRegion == NULL) return;
    printf("\n\nAcompanhe sua trajetória até a vitória\nRegião: **%s**, Enfrentou: **%s**\n", currentRegion->regionName, currentRegion->enemy->name);
    printPath(currentRegion->lastRegion);
}


void showRegion(Region *currentRegion){
    printf("\n🌟 Você entrou na região: **%s** 🌟\n", currentRegion->regionName);
    printf("Inimigo encontrado: %s (HP: %d)\n", currentRegion->enemy->name, currentRegion->enemy->heathPoints);
}
