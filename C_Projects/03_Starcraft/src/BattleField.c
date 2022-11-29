#include "BattleField.h"
#include "TerranTurn.h"
#include "Protoss.h"
#include "ProtossTurn.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
    battleField->terranFleet = (Vector *)malloc(sizeof(Vector));
    vectorInit(battleField->terranFleet, strlen(terranFleetStr));
    size_t playerCount = 0;

    while (playerCount < strlen(terranFleetStr))
    {

        if (terranFleetStr[playerCount] == 'v')
        {
            TerranShip *viking = getVikingShip();
            vectorPush(battleField->terranFleet, viking);
            playerCount++;
        }
        else if (terranFleetStr[playerCount] == 'b')
        {
            TerranShip *battleCruser = getBattleCruser();
            vectorPush(battleField->terranFleet, battleCruser);
            playerCount++;
        }
        else
        {
            printf("Incorrectly entered ship name.");
            exit(1);
        }
    }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{
    battleField->protossFleet = (Vector *)malloc(sizeof(Vector));
    vectorInit(battleField->protossFleet, strlen(protossFleetStr));
    size_t playerCount = 0;

    while (playerCount < strlen(protossFleetStr))
    {
        if (protossFleetStr[playerCount] == 'p')
        {
            ProtossShip *phoenix = getPhoenixShip();
            vectorPush(battleField->protossFleet, phoenix);
            playerCount++;
        }
        else if (protossFleetStr[playerCount] == 'c')
        {
            ProtossShip *carrier = getCarrier();
            vectorPush(battleField->protossFleet, carrier);
            carrier = NULL;
            playerCount++;
        }
        else
        {
            printf("Incorrectly entered ship name.");
            exit(1);
        }
    }
}

void startBattle(BattleField *battleField)
{
    while (true)
    {
        if (processTerranTurn(battleField))
        {
            printf("TERRAN has won!\n");
            return;
        }
        if (processProtossTurn(battleField))
        {
            printf("PROTOSS has won!\n");
            return;
        }
    }
}

void deinit(BattleField *battleField, size_t terranSize, size_t protossSize)
{
    for (size_t i = 0; i < terranSize; i++)
    {
        TerranShip *ship = vectorGet(battleField->terranFleet, i);
        free(ship);
        ship = NULL;
    }
    for (size_t i = 0; i < protossSize; i++)
    {
        ProtossShip *ship = vectorGet(battleField->protossFleet, i);
        free(ship);
        ship = NULL;
    }

    vectorFree(battleField->terranFleet);
    vectorFree(battleField->protossFleet);
    free(battleField->terranFleet);
    free(battleField->protossFleet);
    battleField->terranFleet = NULL;
    battleField->protossFleet = NULL;
    free(battleField);
    battleField = NULL;
}

bool processTerranTurn(BattleField *battleField)
{
    bool checkAlive = terranAttack(battleField->terranFleet, battleField->protossFleet);
    return checkAlive;
}

bool processProtossTurn(BattleField *battleField)
{
    bool checkAlive = protossAttack(battleField->protossFleet, battleField->terranFleet);
    return checkAlive;
}
