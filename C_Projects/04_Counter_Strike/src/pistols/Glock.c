#include "pistols/Glock.h"
#include "pistols/PistolCommonFunctionality.h"
#include <stdio.h>

static void glockDamage(Player *victim, int fighterPistolDamage)
{
    if (getArmor(victim->playerData) <= 0)
    {
        reduceHealth(&(victim->playerData), fighterPistolDamage);
    }
    else
    {
        int damage = fighterPistolDamage / 2;
        reduceArmor(&(victim->playerData), damage);
        reduceHealth(&(victim->playerData), damage);
    }
    //victim->pistol.remainingAmmo = 0;
}


bool processGlockDamage(Player *victim, Pistol* fighterPistol)
{
    for (int i = 0; i < ROUNDS_PER_FIRE; i++)
    {
        if(isPistolEmpty(*fighterPistol))
        {
            reaload(fighterPistol);
            return false;
        }
        glockDamage(victim, getDamage(*fighterPistol));
        reduceClipBullets(fighterPistol);
        printf("Enemy left with: %d health and %d armor\n",getHealth(victim->playerData), getArmor(victim->playerData));
        if (isVictimDead(victim))
        {
            return true;
        }
    }
    return false;
}