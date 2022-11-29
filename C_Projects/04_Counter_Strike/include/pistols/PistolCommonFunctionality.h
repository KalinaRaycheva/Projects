#ifndef PISTOL_COMMON_FUNCTIONALITY_H
#define PISTOL_COMMON_FUNCTIONALITY_H
#include "Player.h"
#include "Pistol.h"

int getDamage(const Pistol pistol);
void reduceRemainingAmmo(Pistol *pistol, int ammo);
void reduceClipBullets(Pistol *pistol);
bool isPistolEmpty(Pistol pistol);
void reaload(Pistol* pistol);

#endif