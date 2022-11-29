#ifndef PROTOSS_TURN_H
#define PROTOSS_TURN_H

#include "Protoss.h"
#include "Helper.h"
#include "Terran.h"

void regenerateProtossShip(ProtossShip *ship);
size_t checkCarrierHealt(ProtossShip *ship);
bool protossAttack(Vector *protoss, Vector *terran);

#endif