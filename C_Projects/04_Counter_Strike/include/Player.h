#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>

#include "pistols/Pistol.h"
#include "Defines.h"

typedef struct
{
  int health;
  int armor;
} PlayerVitalData;

typedef struct
{
  PlayerVitalData playerData;
  Pistol pistol;
  int playerId;
} Player;

int getArmor(PlayerVitalData playerData);
int getHealth(PlayerVitalData playerData);
void setArmor(PlayerVitalData *playerData, int armor);
void setHealth(PlayerVitalData *playerData, int health);
void reduceArmor(PlayerVitalData *playerData, int damage);
void reduceHealth(PlayerVitalData *playerData, int damage);
bool isVictimDead(Player *victim);

#endif /* PLAYER_H_ */