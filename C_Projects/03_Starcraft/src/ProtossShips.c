#include "Protoss.h"
#include <stdlib.h>

ProtossShip *initProtossShip(){
    ProtossShip *protossShip = (ProtossShip*)malloc(sizeof(ProtossShip));
    return protossShip;
}

ProtossShip *getPhoenixShip(){
    ProtossShip *phoenix = initProtossShip();
    phoenix->health = PHOENIX_HEALTH;
    phoenix->damage = PHOENIX_DAMAGE;
    phoenix->shield = PHOENIX_SHIELD;
    phoenix->shield_regeneration = PHOENIX_SHIELD_REGENERATE_RATE;
    phoenix->type = PHOENIX;
    return phoenix;
}

ProtossShip *getCarrier(){
    ProtossShip *carrier = initProtossShip();
    carrier->health = CARRIER_HEALTH;
    carrier->damage = CARRIER_DAMAGE;
    carrier->shield = CARRIER_SHIELD;
    carrier->shield_regeneration = CARRIER_SHIELD_REGENERATE_RATE;
    carrier->type = CARRIER;
    return carrier;
}