#include "ProtossTurn.h"

bool checkTerransFleet(TerranShip **target, ProtossShip *fighter, Vector *terran, int index){
    char *name = getShipName(fighter->type);
    if (isTerranDead(*target)){
        printf("%s with ID: %d killed enemy airship with ID: %ld\n", name, index, vectorGetSize(terran) - 1);
        vectorPop(terran);
        free(*target);
        (*target) = NULL;
    }
    free(name);
    name = NULL;
    if (checkEmptyFleet(terran)){
        return true;
    }
    (*target) = vectorBack(terran);
    return false;
}

void protossMakesDamage(ProtossShip **protos, TerranShip **terran){
    (*terran)->health = (*terran)->health - (*protos)->damage;
}

bool isCarrier(ProtossShip *ship){
    return ship->type == CARRIER;
}

size_t checkCarrierHealt(ProtossShip *ship){
    if (ship->health != CARRIER_HEALTH){
        return DAMAGED_STATUS_INTERCEPTORS;
    }
    return MAX_INTERCEPTORS;
}

void regenerateProtossShip(ProtossShip *ship){
    if (ship->type == PHOENIX){
        ship->shield += ship->shield_regeneration;
        if (ship->shield > PHOENIX_SHIELD){
            ship->shield = PHOENIX_SHIELD;
        }
    }
    else if (ship->type == CARRIER){
        ship->shield += ship->shield_regeneration;
        if (ship->shield > CARRIER_SHIELD){
            ship->shield = CARRIER_SHIELD;
        }
    }
}

bool protossAttack(Vector *protoss, Vector *terran){
    size_t numberOfProtossShips = vectorGetSize(protoss);
    TerranShip *victim = vectorBack(terran);

    for (size_t index = 0; index < numberOfProtossShips; index++){
        ProtossShip *fighter = vectorGet(protoss, index);
        if (isCarrier(fighter)){
            size_t attacks = checkCarrierHealt(fighter);
            for (size_t interceptor = 0; interceptor < attacks; interceptor++){
                protossMakesDamage(&fighter, &victim);
                if (checkTerransFleet(&victim, fighter, terran, index)){
                    return true;
                }
            }
        }
        else{
            protossMakesDamage(&fighter, &victim);
        }

        if (checkTerransFleet(&victim, fighter, terran, index)){
            return true;
        }
        victim = vectorBack(terran);
    }
    printf("Last Terran AirShip with ID: %ld has %d health left\n", vectorGetSize(terran) - 1, victim->health);
    regenerateProtossShip(vectorBack(protoss));
    return false;
}
