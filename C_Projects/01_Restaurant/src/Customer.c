#include "Customer.h"
#include "defines.h"
#include <stdlib.h>

struct customer
{
    int nr_orders;
    int menuIDs;
};

Customer *newCustomer(void)
{
    Customer *tmpCustomer = (Customer *)malloc(sizeof(struct customer));
    tmpCustomer->nr_orders = (rand() % MAX_ORDERS) + 1;
    tmpCustomer->menuIDs = (rand() % MAX_ORDER_ID) + 1;

    return tmpCustomer;
}

int getNumberOfOrder(Customer *customer)
{
    return customer->nr_orders;
}

int getDishMenuID(Customer *customer)
{
    return customer->menuIDs;
}
