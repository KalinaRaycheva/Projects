#include "pistols/PistolCommonFunctionality.h"
#include <stdbool.h>
#include <stdio.h>

static int getPistolCurrentClipBullets(Pistol pistol)
{
    return pistol.currClipBullets;
}

static int getRemainingAmmo(Pistol pistol)
{
    return pistol.remainingAmmo;
}

static void realoadClipBullets(Pistol *pistol, int bullets)
{
    (pistol->currClipBullets) += bullets;
}

static bool checkAmmo(Pistol pistol)
{
    if (pistol.remainingAmmo <= 0)
    {
        return false;
    }
    return true;
}

static bool checkFullRealoadingPossible(int remainigAmmo, int clipSize)
{
    if (remainigAmmo >= clipSize)
    {
        return true;
    }
    return false;
}

int getDamage(Pistol pistol)
{
    return pistol.damagePerRound;
}

void reduceClipBullets(Pistol *pistol)
{
    (pistol->currClipBullets) -= 1;
}

void reduceRemainingAmmo(Pistol *pistol, int ammo)
{
    (pistol->remainingAmmo) -= ammo;
}

bool isPistolEmpty(Pistol pistol)
{
    if (pistol.currClipBullets <= 0)
    {
        return true;
    }
    return false;
}
void reaload(Pistol* pistol)
{   
    if(checkAmmo(*pistol))
    {
        if (checkFullRealoadingPossible(pistol->remainingAmmo, pistol->clipSize))
        {
            realoadClipBullets(pistol, pistol->clipSize);
            reduceRemainingAmmo(pistol, pistol->clipSize);
        }
        else
        {
            realoadClipBullets(pistol, pistol->remainingAmmo);
            reduceRemainingAmmo(pistol, pistol->remainingAmmo);
        }
        printf("Reloading...\n");
        printf("currClipBullets: %d, remainingAmmo: %d\n", getPistolCurrentClipBullets(*pistol), getRemainingAmmo(*pistol));
    }
    else
    {
        printf("No ammo left\n");
    }
}
