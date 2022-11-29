#ifndef CAST_SPELL_H
#define CAST_SPELL_H

#include "Hero.h"

int *readCommands();
void castSpells(int *commands, Hero *heroes[]);
void castBasicSpell(Hero *heroes[]);
void castUltimateSpell(Hero *heroes[]);
void regenerateAll(Hero *heroes[]);
void deinitCommands(int *commands);

#endif /* CAST_SPELL_H */
