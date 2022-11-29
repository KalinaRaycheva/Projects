#include "Hero.h"
#include "SpellInit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void (*heroSpellInit[HEROES])(Hero *hero) = {archmageSpellsInit, deathKnightSpellsInit, drawRangerSpellsInit};

void heroInit(Hero **hero, const char *inputName, int inputMaxMana, int inputManaRegenRate)
{
    (*hero) = (Hero *)malloc(sizeof(Hero));
    strcpy((*hero)->name, inputName);
    (*hero)->maxMana = inputMaxMana;
    (*hero)->manaRegenRate = inputManaRegenRate;
    (*hero)->currMana = inputMaxMana;
}

void fillUserData(Hero* heroes[], const char *inputName, int inputMaxMana, int inputManaRegenRate, int indexOfHero)
{
	heroInit(&heroes[indexOfHero], inputName, inputMaxMana, inputManaRegenRate);
	heroSpellInit[indexOfHero](heroes[indexOfHero]);
}

void getUserData(Hero *heroes[])
{
	char name[MAX_HERO_NAME_SIZE + 1];
	int maxMana = 0;
	int baseManaRegenRate = 0;
	int manaRegenModifier = 0;

	for (size_t heroIndex = 0; heroIndex < HEROES; heroIndex++)
	{
		if (heroIndex == ARCHMAGE_INDEX)
		{
			scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
			fillUserData(heroes, name, maxMana, baseManaRegenRate * manaRegenModifier, ARCHMAGE_INDEX);
		}
		else
		{
			scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
			fillUserData(heroes, name, maxMana, baseManaRegenRate, heroIndex);
		}
	}
}

void deinitHeroes(Hero *heroes[])
{
	for (size_t heroIndex = 0; heroIndex < HEROES; heroIndex++)
	{
		free(heroes[heroIndex]);
		heroes[heroIndex] = NULL;
	}
}
