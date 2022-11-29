#ifndef STARCRAFT_TERRAN_H
#define STARCRAFT_TERRAN_H

#include "Defines.h"
#include "Vector.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int health;
    int damage;
    enum AirShipType type;
} TerranShip;

TerranShip *initTerranShip();
TerranShip *getVikingShip();
TerranShip *getBattleCruser();

#endif // STARCRAFT_TERRAN_H
