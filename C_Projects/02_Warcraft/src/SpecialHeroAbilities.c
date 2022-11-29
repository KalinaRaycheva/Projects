#include "SpecialHeroAbilities.h"
#include <stdio.h>

void activateSpellForFree(Hero *hero, int index)
{
    printf("%s casted %s for %d mana\n", hero->name, hero->spells[index].name, FREE_MANA);
}

void checkDeathKnight(Hero *hero, int indexOfSpell, bool resultFromLastSpell)
{
    if (resultFromLastSpell && indexOfSpell == ULTIMATE)
    {
        activateSpellForFree(hero, BASIC);
    }
}

void regenerateCurrent(Hero *hero)
{
    hero->currMana += hero->manaRegenRate;
    if (hero->currMana > hero->maxMana)
    {
        hero->currMana = hero->maxMana;
    }
}

void checkArchmage(Hero *hero, int indexOfSpell, bool resultFromLastSpell)
{
    if (resultFromLastSpell && indexOfSpell == ULTIMATE)
    {
        regenerateCurrent(hero);
    }
}

void checkDrawRanger(Hero *hero, int indexOfSpell, bool resultFromLastSpell)
{
    if (resultFromLastSpell && indexOfSpell == BASIC)
    {
        activateSpellForFree(hero, BASIC);
    }
}
bool isBasicSpellSuccessful(Hero *hero)
{
    if (hero->spells[BASIC].manaCost <= hero->currMana)
    {
        hero->currMana -= hero->spells[BASIC].manaCost;
        printf("%s casted %s for %d mana\n", hero->name, hero->spells[BASIC].name, hero->spells[BASIC].manaCost);
        return true;
    }
    printf("%s - not enough mana to cast %s\n", hero->name, hero->spells[BASIC].name);
    return false;
}

bool isUltimateSpellSuccessful(Hero *hero)
{
    if (hero->spells[ULTIMATE].manaCost <= hero->currMana)
    {
        hero->currMana -= hero->spells[ULTIMATE].manaCost;
        printf("%s casted %s for %d mana\n", hero->name, hero->spells[ULTIMATE].name, hero->spells[ULTIMATE].manaCost);
        return true;
    }
    printf("%s - not enough mana to cast %s\n", hero->name, hero->spells[ULTIMATE].name);
    return false;
}