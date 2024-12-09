#include "Character.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Character *createCharacter(char *name, int hp, int atk, int def)
{
    Character *newCharcarter = (Character *)malloc(sizeof(Character));
    strcpy(newCharcarter->name, name);
    newCharcarter->heathPoints = hp;
    newCharcarter->attackPoints = atk;
    newCharcarter->defensePoints = def;
    newCharcarter->escapePoints = 0;
    return newCharcarter;
}

int isAlive(Character *character)
{
    return character->heathPoints > 0;
}

void showStatus(Character *player) {
    printf("\n\n===== Status do Personagem =====\n");
    printf("Pontos de Vida: %d\n", player->heathPoints);
    printf("Pontos de Ataque: %d\n", player->attackPoints);
    printf("Pontos de Defesa: %d\n", player->defensePoints);
    printf("Pontos de Fuga Restantes: %d\n", player->escapePoints);
    printf("================================\n\n");
}


void attack(Character *attacker, Character *defender)
{
    int damage = attacker->attackPoints - defender->defensePoints;
    if (damage < 0)
        damage = 0;
    if (damage > defender->heathPoints)
        damage = defender->heathPoints;
    defender->heathPoints -= damage;
    printf("\n🔥 %s atacou %s e causou %d de dano!\n", attacker->name, defender->name, damage);
}

void upgradeStatus(Character *character)
{
    int option;
    while (option < 0 || option > 3)
    {
        printf("\nEscolha um dos atributos para aumentar os pontos:\n");
        printf("1 - Vida\n2 - Ataque\n3 - Defesa\n");
        printf("Entre com o número da opção desejada: ");
        scanf("%d", &option);

        if (option <= 0 || option >= 4)
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    switch (option)
    {
    case 1:
        character->heathPoints += 10;
        printf("\n❤ Vida aumentada para %d!\n", character->heathPoints);
        break;
    case 2:
        character->attackPoints += 10;
        printf("\n⚔️ Ataque aumentado para %d!\n", character->attackPoints);
        break;
    case 3:
        character->defensePoints += 5;
        printf("\n Defesa aumentada para %d!\n", character->defensePoints);
        break;
    }
}