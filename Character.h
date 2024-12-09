#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct
{
    char name[100];
    int heathPoints;
    int attackPoints;
    int defensePoints;
    int escapePoints;
} Character;

Character *createCharacter(char *name, int hp, int atk, int def);
int isAlive(Character *character);
void upgradeStatus(Character *character);
void attack(Character *attacker, Character *defender);
void showStatus(Character *player);

#endif