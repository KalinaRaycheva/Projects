#include "BattleField.h"
#include "pistols/Fire.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void checkBattleField(BattleField *bf)
{
  if (bf == NULL)
  {
    perror("Structure is empty!\n");
    exit(1);
  }
}

static bool processTurnOfFirstPlayer(BattleField *bf)
{
    bool checkAlive = fire(vectorGet(&bf->players,PLAYER_ONE),vectorGet(&bf->players,PLAYER_TWO));
    return checkAlive;
}

static bool processTurnOfSecondPlayer(BattleField *bf)
{
    bool checkAlive = fire(vectorGet(&bf->players,PLAYER_TWO),vectorGet(&bf->players,PLAYER_ONE));
    return checkAlive;
}

void startBattle(BattleField *bf)
{
    checkBattleField(bf);
    while (true)
    {
      if (processTurnOfFirstPlayer(bf))
      {
        printf("\nPlayer with ID: 0 wins!\n");
        return;
      }

      if (processTurnOfSecondPlayer(bf))
      {
        printf("\nPlayer with ID: 1 wins!\n");
        return;
      }
    }
}

