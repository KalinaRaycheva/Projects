#include "Kitchen.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "tables.h"
#include "DishQueue.h"

#define MAX_DISH_COUNT 6

/*UNFINISHED. FINISH SO IT WORKS*/

/**
 * This is your Chef. The heart of your business. He is defined by his Name and the maximum number of dishes he can cook.
 * To work, he needs to have free CookingSlots and know the Dish he is making. Slots are tracked via dishCounter.
 */
struct cook
{
    int maxDishes;
    int dishCounter;
    bool isCooking;
    string ChefName;
    Dish *DishesCooked[];
};

static struct cook *chef = NULL;

/**
 * If the restaurant has no Chef, you can hire one. Otherwise you will have to fire him first. You can have a SINGLE one!
 * @param Name - Name of the newly hired Chef
 * @param maxDishes - How many dishes can he cook at once
 */
void hireChef(char *Name)
{
    srand(time(0));
    if (chef == NULL)
    {
        chef = (Chef *)malloc(sizeof(struct cook));
        chef->isCooking = FALSE;
        chef->maxDishes = rand() % MAX_DISH_COUNT + 1;
        chef->dishCounter = 0;
        chef->ChefName = Name;

        for (int i = 0; i < chef->maxDishes; i++)
        {
            chef->DishesCooked[i] = (Dish *)malloc(sizeof(Dish *));
            chef->DishesCooked[i] = NULL;
        }
    }
}

/**
 * Calls your Chef. "You rang, Boss?" - he answers
 * @return Returns a pointer to your Chef
 */
Chef *callChef(void)
{
    return chef;
}

/**
 * If the cook has free slots, he can take another Dish to cook
 * @param Dish - Pointer to the Dish ordered
 */

void takeOrder(Dish *Dish, int position)
{
    if (chef->dishCounter < chef->maxDishes)
    {
        chef->DishesCooked[position] = Dish;
        chef->dishCounter++;
    }
    else
    {
        printf("No free slots !");
    }
}

/**
 * Checks if a Dish is cooked.
 * @return Returns TRUE if Dish is ready. If not decreases the cooking timer by 1 unit.
 */
bool cookingTimer(dishQueue *dishQ, float *totalProfit)
{
    int tmpTime = 0;
    Dish *tmpDish = NULL;
    Table *tmpTable = NULL;
    bool check = false;

    for (int i = 0; i < chef->maxDishes; i++)
    {
        if (chef->DishesCooked[i] != NULL)
        {
            if ((getDishTimer(chef->DishesCooked[i])) == 0)
            {
                tmpTable = getDishTable(chef->DishesCooked[i]);
                printf("On table %d %s is ready!!\n", getTableNumber(tmpTable), getDishName(chef->DishesCooked[i]));
                freeTableAfterCustomer(&tmpTable);
                *totalProfit += getDishPrice(chef->DishesCooked[i]);
                chef->DishesCooked[i] = NULL;
                chef->dishCounter--;
                if (isEmptyDish(dishQ))
                {
                    takeOrder(deQueueDish(dishQ), i);
                }
                check = true;
            }
            else
            {
                tmpDish = chef->DishesCooked[i];
                tmpTime = getDishTimer(tmpDish);
                tmpTime--;
                setCookingTime(&tmpDish, tmpTime);
            }
        }
    }

    return check;
}

int getChefMaxDishCount()
{
    return chef->maxDishes;
}

/**
 * Print array from dish that chef cooked.
 */
void printCookedArray()
{
    printf("The chef Sashko can cook - %d dishes.\n", getChefMaxDishCount());
}

/**
 * Free chef memory
 */
void freeChef()
{
    free(chef);
}