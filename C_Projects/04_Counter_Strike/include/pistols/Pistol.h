#ifndef PISTOL_H_
#define PISTOL_H_

#include "BattleField.h"
#include "Defines.h"

typedef struct {
  enum PistolType pistolType;
  int damagePerRound;
  int clipSize;
  int currClipBullets;
  int remainingAmmo;
} Pistol;


#endif /* PISTOL_H_ */
