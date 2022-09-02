#ifndef GROUP_TASK1_KITCHEN_H
#define GROUP_TASK1_KITCHEN_H

#include "defines.h"
#include "Dish.h"
#include "DishQueue.h"
#include "tables.h"
#include <stdbool.h>

typedef struct cook Chef;

void hireChef(char *Name);
Chef* callChef(void);
void takeOrder(Dish *Dish, int position);
bool cookingTimer(dishQueue *dishQ,float * totalProfit);
int getChefMaxDishCount();
void printCookedArray();
void freeChef();

#endif //GROUP_TASK1_KITCHEN_H
