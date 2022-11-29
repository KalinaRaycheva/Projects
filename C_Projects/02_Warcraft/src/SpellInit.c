#include "SpellInit.h"
#include <string.h>

void (*spells[MAX_SPELLS])(Hero *hero, const char *spellName, int manaCost) = {basicSpellInit, ultimateSpellInit};

void basicSpellInit(Hero *hero, const char *basicSpellName, int basicSpellManaCost)
{
    strcpy(hero->spells[BASIC].name, basicSpellName);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
}

void ultimateSpellInit(Hero *hero, const char *ultimateSpellName, int ultimateSpellManaCost)
{
    strcpy(hero->spells[ULTIMATE].name, ultimateSpellName);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;
}

void archmageSpellsInit(Hero *hero)
{
    spells[BASIC](hero, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST);
    spells[ULTIMATE](hero, ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
}

void deathKnightSpellsInit(Hero *hero)
{
    spells[BASIC](hero, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST);
    spells[ULTIMATE](hero, DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
}

void drawRangerSpellsInit(Hero *hero)
{
    spells[BASIC](hero, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST);
    spells[ULTIMATE](hero, DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
}