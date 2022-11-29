#ifndef SPELL_INIT_H
#define SPELL_INIT_H

#include "Hero.h"

void basicSpellInit(Hero* hero, const char* basicSpellName, int basicSpellManaCost);
void ultimateSpellInit(Hero* hero, const char* ultimateSpellName, int ultimateSpellManaCost);
void archmageSpellsInit(Hero *hero);
void deathKnightSpellsInit(Hero *hero);
void drawRangerSpellsInit(Hero *hero);

#endif /* SPELL_INIT_H */