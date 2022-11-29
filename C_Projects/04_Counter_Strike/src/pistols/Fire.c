#include "pistols/Fire.h"
#include "pistols/Pistol.h"
#include "pistols/Glock.h"
#include "pistols/DesertEagle.h"
#include <stdio.h>

static bool (*pistolDamageFunctions[NUMBER_OF_PISTOLS])(Player *victim, Pistol* fighterPistol) = {processGlockDamage, processDesertEagleDamage};

static bool victimTakeDamage(Player *victim, Pistol *fighterPistol)
{
    if(pistolDamageFunctions[fighterPistol->pistolType](victim, fighterPistol))
    {
        return true;
    }
    return false;
}

bool fire(Player *fighter, Player *victim)
{
    printf("\nPlayerID %d turn:\n", fighter->playerId);
    return victimTakeDamage(victim, &(fighter->pistol));
}