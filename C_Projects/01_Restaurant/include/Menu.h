#ifndef MENU_H
#define MENU_H
#include "defines.h"
#include "Fridge.h"
#include "Dish.h"

Dish **menu(Product *fridge);
Dish **init_menu();
void fill_menu(Dish **menu, Product *fridge);
void put_dish(Dish *menu, int id, Product *fridge);
string *init_ingredients(int count);
void freeMenu(Dish **menuu);

#endif