#include <stdlib.h>
#include "PlayerInit.h"
#include "BattleField.h"

int main() {
  BattleField battleField;

  initPlayers(&battleField);
  buyPistols(&battleField);

  startBattle(&battleField);

  deinit(&battleField);
  return EXIT_SUCCESS;
}
