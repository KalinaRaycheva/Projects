#ifndef GROUP_TASK1_TABLES_H
#define GROUP_TASK1_TABLES_H
#define MAX_TABLES 8
#define MAX_ORDERS_TABLE 2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
#include "CustomersList.h"
#include "Customer.h"

typedef struct table Table;

Table **initTables();
Table *newTable(int i);
bool getIsFree(Table *table);
Customer *getCustomer(Table *table);
void firstTakeTable(Table **tables, allCustomersQueue *todayCustomersList);
int afterClientIsDone(Table **tables, allCustomersQueue *todayCustomersList);
void freeTableAfterCustomer(Table **tables);
Table *getTable(Table *table);
int getTableNumber(Table *table);
void fillTable(Table **tables, allCustomersQueue *todayCustomersList);
void freeTables(Table **tables);
void printTable(Table **allTables);

#endif // GROUP_TASK1_TABLES_H