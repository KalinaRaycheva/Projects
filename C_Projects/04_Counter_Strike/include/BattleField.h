#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Player.h"
#include "Vector.h"
typedef struct {
  Vector players;
} BattleField;

void startBattle(BattleField* bf);

#endif /* BATTLEFIELD_H_ */
