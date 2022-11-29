#ifndef HERO_H
#define HERO_H

#include "Defines.h"

typedef struct
{
  char name[MAX_SPELL_NAME_SIZE];
  int manaCost;
} Spell;

typedef struct
{
  Spell spells[MAX_SPELLS];
  char name[MAX_HERO_NAME_SIZE];
  int maxMana;
  int currMana;
  int manaRegenRate;
} Hero;

void getUserData(Hero *heroes[]);
void heroInit(Hero **hero, const char *inputName, int inputMaxMana, int inputManaRegenRate);
void deinitHeroes(Hero *heroes[]);

#endif /* HERO_H */
