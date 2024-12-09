#include <stdio.h>
#include <string.h>
#include "Character.h"
#include "Region.h"
#include "Battle.h"
#include "Game.h"

void optionsGame(Character *player)
{
    printf("\n👑 Bem-vindo ao jogo! Você é o herói e deve sobreviver até a última rodada enfrentando os inimigos de cada região.\n");
    selectGamemode(player);
}

void selectGamemode(Character *player)
{
    int choice = -1;
    while (choice < 0 || choice > 3)
    {
        printf("\nSelecione o modo de jogo:\n1- Fácil\n2- Normal\n3- Díficil\nEntre como o dígito da opção desejada: ");
        scanf("%d", &choice);
    }

    switch (choice)
    {
    case 1:
        player->heathPoints += 20;
        player->attackPoints += 15;
        player->defensePoints += 10;
        player->escapePoints = 3;
        break;
    case 2:
        player->escapePoints = 3;
        break;
    default:
        player->escapePoints = 1;
        break;
    }
}

void startGame(Character *player, Region *currentRegion)
{
    optionsGame(player);
    showStatus(player);
    int choice;

    while (currentRegion != NULL && isAlive(player))
    {
        showRegion(currentRegion);
        choice = getPlayerChoice();

        if (choice == 1)
        {
            if (!handleBattle(player, currentRegion))
                break;

            if (!chooseNextPath(&currentRegion))
                break;
        }
        else if (choice == 2)
        {
            if (!handleEscape(player, &currentRegion))
                break;
        }
        else
        {
            printf("\n❌ Opção inválida.\n");
        }
    }
}

int getPlayerChoice()
{
    int choice = -1;
    printf("Deseja enfrentar o inimigo ou fugir?\n1 - Enfrentar\n2 - Fugir\nEntre com o dígito da opção desejada: ");
    scanf("%d", &choice);
    return choice;
}

int handleBattle(Character *player, Region *currentRegion)
{
    battle(player, currentRegion);

    if (!isAlive(player))
    {
        printf("\n🔚 Game Over! Você foi derrotado.\n");
        return 0;
    }

    return 1;
}

int chooseNextPath(Region **currentRegion)
{
    if (((*currentRegion)->left == NULL || (*currentRegion)->left == NULL))
    {
        printf("\n🎉 Parabéns! Você completou o jogo. 🎉\n");
        printPath(*currentRegion);
        return 0;
    }

    int choice;
    printf("Escolha o próximo caminho:\n1 - Esquerda (%s)\n2 - Direita (%s)\n",
           (*currentRegion)->left->regionName,
           (*currentRegion)->right->regionName);
    scanf("%d", &choice);

    if (choice == 1 && (*currentRegion)->left != NULL)
    {
        *currentRegion = (*currentRegion)->left;
    }
    else if (choice == 2 && (*currentRegion)->right != NULL)
    {
        *currentRegion = (*currentRegion)->right;
    }
    else
    {
        printf("\n❌ Caminho inválido! O jogo terminou.\n");
        return 0;
    }

    return 1;
}

int handleEscape(Character *player, Region **currentRegion)
{
    if (strcmp((*currentRegion)->regionName, "Aldeia") == 0)
    {
        printf("\n🚫 Você não pode fugir da Aldeia!\n");
        return 1;
    }

    printf("\nVocê fugiu da região **%s**.\n", (*currentRegion)->regionName);
    player->escapePoints--;

    if (player->escapePoints == 0)
    {
        printf("\n🔚 Game Over! Você decidiu abandonar sua missão.\n");
        return 0;
    }

    *currentRegion = (*currentRegion)->lastRegion;
    return 1;
}
