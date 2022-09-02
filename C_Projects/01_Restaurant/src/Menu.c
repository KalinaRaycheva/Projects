#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dish.h"
#include "Menu.h"
#include "Fridge.h"

/**
 * Makes a menu of dishes.
 */
Dish **menu(Product *fridge)
{
    Dish **menu = init_menu();
    fill_menu(menu, fridge);
    return menu;
}

Dish **init_menu()
{
    Dish **menu = (Dish **)malloc(MAX_ORDER_ID * sizeof(Dish *));
    for (int i = 0; i < MAX_ORDER_ID; i++)
    {
        menu[i] = newDish();
    }
    return menu;
}

/**
 * Fill the menu with dishes.
 * @param menu - the menu we want to fill
 * @param fridge  -  the place where all products are
 */
void fill_menu(Dish **menu, Product *fridge)
{
    for (int i = 0; i < MAX_ORDER_ID; i++)
    {
        put_dish(menu[i], i + 1, fridge);
    }
}

/**
 * Puts into current place the dish with current id.
 * @param menu - the menu we want to fill
 * @param fridge  -  the place where all products are
 */
void put_dish(Dish *menu, int id, Product *fridge)
{
    string *products;
    int num_ingredients = 0;
    switch (id)
    {
    case 1:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 15);
        setDishPrice(&menu, 6.0);
        setDishName(&menu, "pizza");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 0);
        products[1] = getProduct(fridge, 1);
        products[2] = getProduct(fridge, 2);
        products[3] = getProduct(fridge, 3);
        setNeededIngredients(&menu, products);
        break;

    case 2:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 5);
        setDishPrice(&menu, 5.0);
        setDishName(&menu, "sandwich");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 4);
        products[1] = getProduct(fridge, 1);
        products[2] = getProduct(fridge, 5);
        products[3] = getProduct(fridge, 2);
        setNeededIngredients(&menu, products);
        break;

    case 3:
        num_ingredients = 6;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 10);
        setDishPrice(&menu, 7.0);
        setDishName(&menu, "burger");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 6);
        products[1] = getProduct(fridge, 7);
        products[2] = getProduct(fridge, 8);
        products[3] = getProduct(fridge, 9);
        products[4] = getProduct(fridge, 10);
        products[5] = getProduct(fridge, 11);
        setNeededIngredients(&menu, products);
        break;

    case 4:
        num_ingredients = 6;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 10);
        setDishPrice(&menu, 6.5);
        setDishName(&menu, "spaghetti");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 12);
        products[1] = getProduct(fridge, 13);
        products[2] = getProduct(fridge, 14);
        products[3] = getProduct(fridge, 15);
        products[4] = getProduct(fridge, 1);
        products[5] = getProduct(fridge, 2);
        setNeededIngredients(&menu, products);
        break;

    case 5:
        num_ingredients = 5;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 7);
        setDishPrice(&menu, 5.0);
        setDishName(&menu, "risotto");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 16);
        products[1] = getProduct(fridge, 14);
        products[2] = getProduct(fridge, 15);
        products[3] = getProduct(fridge, 17);
        products[4] = getProduct(fridge, 18);
        setNeededIngredients(&menu, products);
        break;

    case 6:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 3);
        setDishPrice(&menu, 5.0);
        setDishName(&menu, "shopska salad");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 1);
        products[1] = getProduct(fridge, 19);
        products[2] = getProduct(fridge, 2);
        setNeededIngredients(&menu, products);
        break;

    case 7:
        num_ingredients = 5;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 3);
        setDishPrice(&menu, 5.0);
        setDishName(&menu, "green salad");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 11);
        products[1] = getProduct(fridge, 20);
        products[2] = getProduct(fridge, 21);
        products[3] = getProduct(fridge, 22);
        products[4] = getProduct(fridge, 1);
        setNeededIngredients(&menu, products);
        break;

    case 8:
        num_ingredients = 5;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 10);
        setDishPrice(&menu, 6.5);
        setDishName(&menu, "roasted vegetables");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 23);
        products[1] = getProduct(fridge, 24);
        products[2] = getProduct(fridge, 25);
        products[3] = getProduct(fridge, 14);
        products[4] = getProduct(fridge, 15);
        setNeededIngredients(&menu, products);
        break;

    case 9:
        num_ingredients = 2;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 10);
        setDishPrice(&menu, 7.0);
        setDishName(&menu, "grilled fish");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 26);
        products[1] = getProduct(fridge, 27);
        setNeededIngredients(&menu, products);
        break;

    case 10:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 7);
        setDishPrice(&menu, 4.5);
        setDishName(&menu, "cream soup");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 28);
        products[1] = getProduct(fridge, 14);
        products[2] = getProduct(fridge, 15);
        products[3] = getProduct(fridge, 29);
        setNeededIngredients(&menu, products);
        break;

    case 11:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 3);
        setDishPrice(&menu, 2.0);
        setDishName(&menu, "puncakes");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 30);
        products[1] = getProduct(fridge, 31);
        products[2] = getProduct(fridge, 8);
        products[3] = getProduct(fridge, 32);
        setNeededIngredients(&menu, products);
        break;

    case 12:
        num_ingredients = 4;
        addToMenu(&menu, id);
        setNumIngredients(&menu, num_ingredients);
        setCookingTime(&menu, 4);
        setDishPrice(&menu, 3.5);
        setDishName(&menu, "melba");

        products = init_ingredients(num_ingredients);
        products[0] = getProduct(fridge, 33);
        products[1] = getProduct(fridge, 34);
        products[2] = getProduct(fridge, 35);
        products[3] = getProduct(fridge, 32);
        setNeededIngredients(&menu, products);
        break;

    default:
        break;
    }
}

string *init_ingredients(int count)
{
    string *products = (string *)malloc(count * sizeof(string));
    for (int i = 0; i < count; i++)
    {
        products[i] = (string)malloc(10 * sizeof(char));
    }
    return products;
}
