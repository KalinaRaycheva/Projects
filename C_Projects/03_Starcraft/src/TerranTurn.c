#include "TerranTurn.h"

void terranMakesDamage(TerranShip **terran, ProtossShip **protos){
    int toSub = (*terran)->damage - (*protos)->shield;

    if (toSub >= 0){
        (*protos)->shield = 0;
        (*protos)->health -= toSub;
    }
    else{
        (*protos)->shield -= (*terran)->damage;
    }
}
void vikingAgainstPhoenix(TerranShip **terran, ProtossShip **protos){
    (*terran)->damage = VIKING_DAMAGE * 2;
    terranMakesDamage(terran, protos);
    (*terran)->damage = VIKING_DAMAGE;
}

bool isViking(TerranShip *ship){
    if (ship->type == VIKING){
        return true;
    }
    return false;
}

bool isBattleCurser(TerranShip *ship){
    if (ship->type == BATTLE_CRUSER){
        return true;
    }
    return false;
}

bool checkForYamatoCannon(TerranShip **ship, int turnsOfBattleCurser){
    if ((*ship)->type == BATTLE_CRUSER){
        if ((turnsOfBattleCurser % YAMATO_CANNON_TURN) == 0){
            return true;
        }
    }
    return false;
}
void activateYamatoCannonPower(TerranShip **ship, ProtossShip **target){
    (*ship)->damage = (*ship)->damage * YAMATO_CANNON_TURN;
    terranMakesDamage(ship, target);
}

void resetBattleCurserDamage(TerranShip **ship){
    (*ship)->damage = BATTLE_CRUSER_DAMAGE;
}

bool checkProtossFleet(ProtossShip **target, Vector *protoss, TerranShip *fighter, int index){
    char *name = getShipName(fighter->type);

    if (isProtossDead(*target)){
        printf("%s with ID: %d killed enemy airship with ID: %ld\n", name, index, vectorGetSize(protoss) - 1);
        vectorPop(protoss);
        free(*target);
        (*target) = NULL;
    }
    free(name);
    name = NULL;

    if (checkEmptyFleet(protoss)){
        return true;
    }
    (*target) = vectorBack(protoss);

    return false;
}

bool terranAttack(Vector *terran, Vector *protoss){
    static int countTurns = 0;
    countTurns++;

    size_t numberOfTerranShips = vectorGetSize(terran);
    ProtossShip *victim = vectorBack(protoss);

    for (size_t index = 0; index < numberOfTerranShips; index++){
        TerranShip *fighter = vectorGet(terran, index);

        if (isPhoenix(victim) && isViking(fighter)){
            vikingAgainstPhoenix(&fighter, &victim);
        }
        else if (isBattleCurser(fighter)){
            if (checkForYamatoCannon(&fighter, countTurns)){
                activateYamatoCannonPower(&fighter, &victim);
                resetBattleCurserDamage(&fighter);
            }
            else{
                terranMakesDamage(&fighter, &victim);
            }
        }
        else{
            terranMakesDamage(&fighter, &victim);
        }

        if (checkProtossFleet(&victim, protoss, fighter, index)){
            return true;
        }
    }

    printf("Last Protoss AirShip with ID: %ld has %d health and %d shield left\n", vectorGetSize(protoss) - 1, victim->health, victim->shield);
    return false;
}
