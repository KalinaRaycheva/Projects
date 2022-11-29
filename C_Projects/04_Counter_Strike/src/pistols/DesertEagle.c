#include "pistols/DesertEagle.h"
#include "pistols/PistolCommonFunctionality.h"
#include <stdio.h>

static void desertEagleDamage(Player *victim, int fighterPistolDamage)
{
    if (getArmor(victim->playerData) <= 0)
    {
        reduceHealth(&(victim->playerData), fighterPistolDamage);
    }
    else
    {
        int damage = fighterPistolDamage / 4;
        reduceHealth(&(victim->playerData), damage * 3);
        reduceArmor(&(victim->playerData), damage);
    }
}

bool processDesertEagleDamage(Player *victim, Pistol* fighterPistol)
{
    if(isPistolEmpty(*fighterPistol))
    {
        reaload(fighterPistol);
        return false;
    }
    desertEagleDamage(victim, getDamage(*fighterPistol));
    reduceClipBullets(fighterPistol);
    printf("Enemy left with: %d health and %d armor\n",getHealth(victim->playerData), getArmor(victim->playerData));
    if (isVictimDead(victim))
    {
        return true;
    }
    return false;
}