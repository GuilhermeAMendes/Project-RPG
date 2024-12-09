#ifndef REGION_H
#define REGION_H

#include "Character.h"

typedef struct _region
{
    char regionName[100];
    Character *enemy;
    struct _region *right;
    struct _region *left;
    struct _region *lastRegion;
} Region;

Region *createRegion(char *regionName, Character *enemy);
void createRegions(Region *parent, Character *enemyList, int numEnemies, int maxDepth);
Character *randomEnemy(Character *listEnemies, int numEnemies);
void printPath(Region *currentRegion);
void showRegion(Region *currentRegion);

#endif