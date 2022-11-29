#ifndef HELPER_H
#define HELPER_H

#include "Protoss.h"
#include "Terran.h"

bool checkEmptyFleet(Vector *fleet);
bool isTerranDead(TerranShip *ship);
bool isProtossDead(ProtossShip *ship);
char *getShipName(enum AirShipType type);
bool isPhoenix(ProtossShip *ship);

#endif