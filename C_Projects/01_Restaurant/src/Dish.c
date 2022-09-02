#include "Dish.h"
#include <stdio.h>
#include <stdlib.h>
#include <tables.h>

/**
 * Used to define a dish within the restaurant OS. Contains menu ID, dish Price, number of ingredients needed,
 * list of ingredient names, the Name of the Dish and a list of ingredient names
 */
struct dish
{
    int menuID;
    int numIngredients;
    int cookingTime;
    float dishPrice;
    string dishName;
    string *ingerdientsList;
    Table *table;
};

/**
 * Creates a new dish with a predefined amount of ingredients.
 * @return A pointer to a dish stored in the memory.
 */
Dish *newDish(void)
{
    struct dish *tmpDish = (struct dish *)malloc(sizeof(struct dish));
    tmpDish->dishName = NULL;
    tmpDish->dishPrice = 0;
    tmpDish->numIngredients = 0;
    tmpDish->cookingTime = 0;
    tmpDish->menuID = 0;
    tmpDish->table = NULL;

    return tmpDish;
}

/**
 * Sets the name of a newly added Dish.
 * @param Dish - the dish that needs to be updated
 * @param Name  - the Name for the new dish
 */
void setDishName(Dish **Dish, string Name)
{
    (*Dish)->dishName = Name;
}

/**
 * Sets the Price of the new Dish.
 * @param Dish - the dish that needs to be updated
 * @param Price - the PRice of the new dish
 */
void setDishPrice(Dish **Dish, float Price)
{
    (*Dish)->dishPrice = Price;
}

/**
 * Sets the total Number of ingredients needed for the new Dish
 * @param Dish - the dish that needs to be updated
 * @param Ingredients - the total amount of ingredients
 */
void setNumIngredients(Dish **Dish, int Ingredients)
{
    (*Dish)->numIngredients = Ingredients;
}

/**
 * Adds a list of ingredients to the dish.
 * @param Dish - the dish that needs to be updated
 * @param Ingredients - the list of ingredients needed
 */
void setNeededIngredients(Dish **Dish, string Ingredients[])
{
    int tmpIngredientsCount = (*Dish)->numIngredients;
    (*Dish)->ingerdientsList = (string *)malloc(tmpIngredientsCount * sizeof(string));
    for (int i = 0; i < tmpIngredientsCount; i++)
    {
        (*Dish)->ingerdientsList[i] = (string)malloc(sizeof(string));
        (*Dish)->ingerdientsList[i] = Ingredients[i];
    }
}

/**
 * Sets the cooking time of the Dish
 * @param Dish - the dish that needs to be updated
 * @param Time - the Time needed to cook the dish
 */
void setCookingTime(Dish **Dish, int Time)
{
    (*Dish)->cookingTime = Time;
}

/**
 * Links the new Dish to the restaurant menu
 * @param Dish - the dish that needs to be updated
 * @param menuID - the number in the menu for the dish
 */
void addToMenu(Dish **Dish, int menuID)
{
    (*Dish)->menuID = menuID;
}

/**
 * Links the dish to the restaurant table
 * @param dish - the dish that needs to be updated
 * @param table - the current table
 */
void setDishTable(Dish **dish, Table *table)
{
    (*dish)->table = table;
}

/**
 * Prints the ingredients of a given dish
 * @param Dish - Pointer to the Dish
 */
void printIngredients(Dish *Dish)
{
    for (int i = 0; i < Dish->numIngredients; i++)
    {
        fputs(Dish->ingerdientsList[i], stdout);
        fputs("\n", stdout);
    }
}

/**
 * Tells how long the Dish needs to be cooked
 * @param Dish - A pointer to a Dish
 * @return Returns the cooking timer
 */
int getDishTimer(Dish *Dish)
{
    return Dish->cookingTime;
}

/**
 * Returns the dish name
 * @param Dish - A pointer to a Dish
 * @return Returns the Dish Name
 */
string getDishName(Dish *Dish)
{
    return Dish->dishName;
}

/**
 * Returns the Number of ingredients needed for the Dish
 * @param Dish - A pointer to a DIsh
 * @return Returns the total number of ingredients needed
 */
int getNumberIngredients(Dish *Dish)
{
    return Dish->numIngredients;
}

/**
 * Returns the Dish Price
 * @param Dish - A pointer tp a Dish
 * @return Returns the Dish Price
 */
float getDishPrice(Dish *Dish)
{
    return Dish->dishPrice;
}

/**
 * Returns the ID from the menu
 * @param Dish - A pointer to a Dish
 * @return Returns the menu number of the Dish as an integer
 */
int getMenuID(Dish *Dish)
{
    return Dish->menuID;
}

/**
 * Returns a list of the Dish ingredients
 * @param Dish - A pointer to a Dish
 * @return Returns the ingredients of the Dish
 */
string *getIngredientsList(Dish *Dish)
{
    return Dish->ingerdientsList;
}

Table *getDishTable(Dish *Dish)
{
    return Dish->table;
}

Dish *GetDishFromId(Dish **menu, int id, Table *table)
{
    Dish *dish = newDish();

    addToMenu(&dish, getMenuID(menu[id - 1]));
    setCookingTime(&dish, getDishTimer(menu[id - 1]));
    setDishPrice(&dish, getDishPrice(menu[id - 1]));
    setDishName(&dish, getDishName(menu[id - 1]));
    setNumIngredients(&dish, getNumberIngredients(menu[id - 1]));
    setNeededIngredients(&dish, getIngredientsList(menu[id - 1]));
    setDishTable(&dish, table);

    return dish;
}

/**
 * Free memory from dish
 * @param Dish - the dish that needs to free
 */
void freeDishesMemory(Dish **dish)
{
    for (int i = 0; i < MAX_ORDER_ID; i++)
    {
        free(dish[i]->ingerdientsList);
        free(*(dish + i));
    }
    free(dish);
}
