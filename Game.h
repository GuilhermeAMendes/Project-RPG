#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Region.h"

void startGame(Character *player, Region *currentRegion);
void selectGamemode(Character *player);
int getPlayerChoice();
int handleBattle(Character *player, Region *currentRegion);
int chooseNextPath(Region **currentRegion);
int handleEscape(Character *player, Region **currentRegion);

#endif
