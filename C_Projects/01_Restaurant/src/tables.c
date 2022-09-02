#include "tables.h"
#include "CustomersList.h"
#include "Customer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct table
{
    int tableNumber;
    bool isFree;
    Customer *customer;
};

Table **initTables()
{
    Table **tables = (Table **)malloc(sizeof(Table *) * MAX_TABLES);
    for (int i = 0; i < MAX_TABLES; i++)
    {
        tables[i] = newTable(i + 1);
    }
    return tables;
}

Table *newTable(int i)
{

    Table *table = (Table *)malloc(sizeof(struct table));
    table->isFree = true;
    table->tableNumber = i;
    table->customer = NULL;
    return table;
}

bool getIsFree(Table *table)
{
    return table->isFree;
}

Customer *getCustomer(Table *table)
{
    return table->customer;
}

int getTableNumber(Table *table)
{
    return table->tableNumber;
}

/**
 * Fill tables with customers.
 * @param tables - the tables thathas to be filled
 * @param todayCustomersList  - the customer list from which we will fill
 */
void fillTable(Table **tables, allCustomersQueue *todayCustomersList)
{
    for (int i = 0; i < MAX_TABLES; i++)
    {
        if (isEmpty(todayCustomersList))
        {
            tables[i]->customer = deQueue(todayCustomersList);
            tables[i]->isFree = false;
        }
    }
}

int afterClientIsDone(Table **tables, allCustomersQueue *todayCustomersList)
{

    for (int i = 0; i < MAX_TABLES; i++)
    {
        if (getIsFree(tables[i]))
        {
            tables[i]->customer = deQueue(todayCustomersList);
            tables[i]->isFree = false;
            return i;
        }
    }
    return -1;
}

/**
 * Free customer memory from tables.
 * @param tables - the tables from where has to free customer memory
 */
void freeTableAfterCustomer(Table **tables)
{
    free((*tables)->customer);
    (*tables)->customer = NULL;
    (*tables)->isFree = true;
}

Table *getTable(Table *table)
{
    return table;
}

/**
 * Free memory from table struct.
 * @param tables - the table struct that has to be free
 */
void freeTables(Table **tables)
{
    for (int i = 0; i < MAX_TABLES; i++)
    {
        free(tables[i]);
    }
    free(tables);
}


/**
 * Print tabel number, number of order and menu id.
 * @param allTables - the table struct from which we will get information
 */
void printTable(Table **allTables)
{
    for (int i = 0; i < 8; i++)
    {
        if (getCustomer(allTables[i]) != NULL)
            printf("Table %d \nNumber of order : %d \nMenu ID : %d \n", i + 1, getNumberOfOrder(getCustomer(allTables[i])), getDishMenuID(getCustomer(allTables[i])));
    }
}