#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"

int main()
{
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  scanf("%s %s", terranFleet, protossFleet);

  BattleField *battleField = (BattleField *)malloc(sizeof(BattleField));

  generateTerranFleet(battleField, terranFleet);
  size_t terranFleetSize = vectorGetSize(battleField->terranFleet);
  generateProtossFleet(battleField, protossFleet);
  size_t protossFleetSize = vectorGetSize(battleField->protossFleet);
  startBattle(battleField);

  deinit(battleField, terranFleetSize,  protossFleetSize);

  return EXIT_SUCCESS;
}
