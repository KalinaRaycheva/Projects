#include "CastSpell.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Hero *heroes[HEROES];
  getUserData(heroes); 
  
  int *commands = readCommands();
  castSpells(commands, heroes);

  deinitHeroes(heroes);
  deinitCommands(commands);

  return EXIT_SUCCESS;
}