#include "Terran.h"
#include <stdlib.h>

TerranShip *initTerranShip(){
    TerranShip *terranShip = (TerranShip*)malloc(sizeof(TerranShip));
    return terranShip;
}

TerranShip *getVikingShip(){
    TerranShip *viking = initTerranShip();
    viking->health = VIKING_HEALTH;
    viking->damage = VIKING_DAMAGE;
    viking->type = VIKING;
    return viking;
}

TerranShip *getBattleCruser(){
    TerranShip *battleCruser = initTerranShip();
    battleCruser->health = BATTLE_CRUSER_HEALTH;
    battleCruser->damage = BATTLE_CRUSER_DAMAGE;
    battleCruser->type = BATTLE_CRUSER;
    return battleCruser;
}
