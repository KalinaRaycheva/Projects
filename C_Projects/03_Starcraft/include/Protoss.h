#ifndef STARCRAFT_PROTOSS_H
#define STARCRAFT_PROTOSS_H

#include "Defines.h"
#include "Vector.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    int health;
    int damage;
    int shield;
    int shield_regeneration;
    enum AirShipType type;
} ProtossShip;

ProtossShip *initProtossShip();
ProtossShip *getPhoenixShip();
ProtossShip *getCarrier();

#endif