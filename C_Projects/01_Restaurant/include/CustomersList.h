#ifndef CUSTOMERSLIST_H
#define CUSTOMERSLIST_H
#include "Customer.h"
#include <stdbool.h>

typedef struct node currentCustomerNode;
typedef struct queue allCustomersQueue;
allCustomersQueue *QueueInit();
allCustomersQueue *letTodayCustomers();

void enQueue(allCustomersQueue *todayCustomersList, Customer *customer);
Customer *deQueue(allCustomersQueue *current);
void printTodayWork(allCustomersQueue *todayCustomersList);
bool isEmpty(allCustomersQueue *todayCustomersList);

#endif