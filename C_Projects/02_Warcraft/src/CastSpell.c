#include "CastSpell.h"
#include "SpecialHeroAbilities.h"
#include <stdio.h>
#include <stdlib.h>

void (*checkHero[HEROES])(Hero *hero, int indexOfSpell, bool resultFromLastSpell) = {checkArchmage, checkDeathKnight, checkDrawRanger};
void (*commandOptions[HEROES])(Hero *hero[]) = {castBasicSpell, castUltimateSpell, regenerateAll};

size_t commandsCount = 0;
int *readCommands()
{
    scanf("%ld", &commandsCount);
    int *commands = malloc(sizeof(int) * commandsCount);

    for (size_t commandIndex = 0; commandIndex < commandsCount; ++commandIndex)
    {
        scanf("%d", &(commands[commandIndex]));
    }
    return commands;
}

void castSpells(int *commands, Hero *hero[])
{
    for (size_t commandIndex = 0; commandIndex < commandsCount; commandIndex++)
    {
        commandOptions[commands[commandIndex]](hero);
    }
}

void castBasicSpell(Hero *heroes[])
{
    bool resultFromLastSpell = false;
    for (size_t heroIndex = 0; heroIndex < HEROES; heroIndex++)
    {
        resultFromLastSpell = isBasicSpellSuccessful(heroes[heroIndex]);
        if (heroIndex == DRAW_RANGER_INDEX)
        {
            checkHero[DRAW_RANGER_INDEX](heroes[DRAW_RANGER_INDEX], BASIC, resultFromLastSpell);
        }
    }
}

void castUltimateSpell(Hero *heroes[])
{
    bool resultFromLastSpell = false;
    for (size_t heroIndex = 0; heroIndex < HEROES; heroIndex++)
    {
        resultFromLastSpell = isUltimateSpellSuccessful(heroes[heroIndex]);
        if (heroIndex == ARCHMAGE_INDEX)
        {
            checkHero[ARCHMAGE_INDEX](heroes[heroIndex], ULTIMATE, resultFromLastSpell);
        }
        if (heroIndex == DEATH_KNIGHT_INDEX)
        {
            checkHero[DEATH_KNIGHT_INDEX](heroes[heroIndex], ULTIMATE, resultFromLastSpell);
        }
    }
}

void regenerateAll(Hero *heroes[])
{
    for (size_t heroIndex = 0; heroIndex < HEROES; heroIndex++)
    {
        regenerateCurrent(heroes[heroIndex]);
    }
}

void deinitCommands(int *commands)
{
    free(commands);
    commands = NULL;
}