#ifndef SPECIAL_HERO_ABILITIES_H
#define SPECIAL_HERO_ABILITIES_H

#include "Hero.h"
#include <stdbool.h>

void activateSpellForFree(Hero *hero, int index);
void regenerateCurrent(Hero* hero);
void checkArchmage(Hero *hero, int indexOfSpell, bool resultFromLastSpell);
void checkDeathKnight(Hero *hero, int indexOfSpell, bool resultFromLastSpell);
void checkDrawRanger(Hero *hero, int indexOfSpell, bool resultFromLastSpell);
bool isBasicSpellSuccessful(Hero *hero);
bool isUltimateSpellSuccessful(Hero *hero);

#endif /* SPECIAL_HERO_ABILITIES_H */