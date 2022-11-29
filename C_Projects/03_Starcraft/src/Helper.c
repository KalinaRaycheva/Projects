#include "Helper.h"

bool checkEmptyFleet(Vector *fleet){
    return vectorIsEmpty(fleet);
}

bool isTerranDead(TerranShip *ship){
    return ship->health <= 0;
}

bool isProtossDead(ProtossShip *ship){
    return ship->health <= 0;
}

bool isPhoenix(ProtossShip *ship){
    if (ship->type== PHOENIX){
        return true;
    }
    return false;
}

char *getShipName(enum AirShipType type){
    char *name = (char *)malloc(sizeof(char) * 15);
    if (type == PHOENIX){
        strcpy(name, "Phoenix");
    }
    else if (type == CARRIER){
        strcpy(name, "Carrier");
    }
    else if (type == VIKING){
        strcpy(name, "Viking");
    }
    else{
        strcpy(name, "Battle Cruser");
    }
    return name;
}
