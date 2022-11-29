#include "Player.h"
#include "pistols/Pistol.h"
#include <stdbool.h>

int getArmor(PlayerVitalData playerData)
{
    return playerData.armor;
}

int getHealth(PlayerVitalData playerData)
{
    return playerData.health;
}

void setArmor(PlayerVitalData *playerData, int armor)
{
    playerData->armor = armor;
}

void setHealth(PlayerVitalData *playerData, int health)
{
    playerData->health = health;
}
void reduceArmor(PlayerVitalData *playerData, int damage)
{
    int div = damage-playerData->armor;
    if(div > 0)
    {
        playerData->armor = RESET;
        reduceHealth(playerData, div);
    }
    else
    {
        (playerData->armor) -= damage;
    }
}

void reduceHealth(PlayerVitalData *playerData, int damage)
{
    (playerData->health) -= damage;
}

bool isVictimDead(Player* victim)
{
    if (getHealth(victim->playerData) <= 0)
    {
        return true;
    }
    return false;
}