#ifndef TERRANTURN_H
#define TERRANTURN_H

#include "Terran.h"
#include "Helper.h"

bool terranAttack(Vector *terran, Vector *protoss);
bool checkForYamatoCannon(TerranShip **ship, int turnsOfBattleCurser);
void resetBattleCurserDamage(TerranShip **ship);

#endif