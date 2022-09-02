#include "restaurant.h"
#include "defines.h"
#include "CustomersList.h"
#include "Kitchen.h"
#include "Customer.h"
#include "Fridge.h"
#include "tables.h"
#include "Dish.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DishQueue.h"

short openForBusiness(void)
{
    allCustomersQueue *todayCustomersList;
    Table **allTables = initTables();
    dishQueue *dishQ;
    Product *fridge = initFridge();
    Dish **menuu = menu(fridge);
    hireChef("Sashsko"); // Sashko si ima harakter.
    Chef *petrov = callChef();
    float totalProfit = 0;

    srand(time(NULL));
    for (int day = 0; day < 10; day++)
    {
        printf("\n--------Day %d--------\n", day + 1);
        todayCustomersList = letTodayCustomers();

        fillTable(allTables, todayCustomersList);

        dishQ = fillDishQ(menuu, allTables);
        printDishQueue(dishQ);

        for (int i = 0; i < getChefMaxDishCount(); i++)
        {
            if (isEmptyDish(dishQ))
                takeOrder(deQueueDish(dishQ), i);
        }
        printCookedArray();

        printf("\n");
        for (int minutes = 0; minutes < 200; minutes++)
        {
            if (cookingTimer(dishQ, &totalProfit))
            {
                if (isEmpty(todayCustomersList))
                {
                    int i = afterClientIsDone(allTables, todayCustomersList);
                    enQueueDish(GetDishFromId(menuu, getDishMenuID(getCustomer(allTables[i])), getTable(allTables[i])), dishQ);
                }
            }
        }
        free(dishQ);
    }
    printf("\nTotal profit of all 10 days is : %0.2f\n", totalProfit);
    printf("After Sashko's salary deduction, the net profit is- -%0.2f\n", totalProfit);
    printf("Maybe we have to close this restaurant and beat up Sashko.");
    freeChef();
    freeDishesMemory(menuu);
    freeTables(allTables);
    freeFridge(fridge);
    return FALSE;
}
