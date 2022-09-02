#include "CustomersList.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct node
{
    Customer *customer;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

allCustomersQueue *QueueInit()
{
    allCustomersQueue *thisQueue = (allCustomersQueue *)malloc(sizeof(*thisQueue));
    thisQueue->front = NULL;
    thisQueue->rear = NULL;
    return thisQueue;
}

allCustomersQueue *letTodayCustomers()
{
    allCustomersQueue *todayCustomersList = QueueInit();
    int today_customers_count = rand() % 10 + 1;
    printf("This day we have %d customers!\n", today_customers_count);
    for (int id = 0; id < today_customers_count; id++)
    {
        Sleep(1000);
        enQueue(todayCustomersList, newCustomer());
    }
    return todayCustomersList;
}

/**
 * Adds a new customer to the today's customer list.
 * @param todayCustomersList - Pointer to the allCustomersQueue
 * @param customer - Pointer to the Customer
 */
void enQueue(allCustomersQueue *todayCustomersList, Customer *customer)
{
    currentCustomerNode *currentNode = (currentCustomerNode *)malloc(sizeof(currentCustomerNode));
    currentNode->customer = customer;
    currentNode->next = NULL;
    if (todayCustomersList->front == NULL)
    {
        todayCustomersList->front = currentNode;
        todayCustomersList->rear = currentNode;
        return;
    }
    todayCustomersList->rear->next = currentNode;
    todayCustomersList->rear = currentNode;
}

Customer *deQueue(allCustomersQueue *current)
{
    currentCustomerNode *elToDeQueue = current->front;
    if (current->front == NULL)
    {
        printf("List of customers is empty !!!");
        return NULL;
    }
    if (current->front == current->rear)
    {
        current->front = current->rear = NULL;
        Customer *temp = elToDeQueue->customer;
        free(elToDeQueue);
        return temp;
    }
    Customer *temp = elToDeQueue->customer;
    current->front = current->front->next;
    free(elToDeQueue);
    return temp;
}

/**
 * Prints the the today's customer list.
 * @param todayCustomersList - Pointer to the allCustomersQueue
 */
void printTodayWork(allCustomersQueue *todayCustomersList)
{
    currentCustomerNode *temp = todayCustomersList->front;
    for (int client_number = 0; temp != NULL; client_number++)
    {
        printf("Client Number %d \nNumber of order : %d \nMenu ID : %d \n", client_number, getNumberOfOrder(temp->customer), getDishMenuID(temp->customer));
        temp = temp->next;
    }
}

bool isEmpty(allCustomersQueue *todayCustomersList)
{
    if (todayCustomersList->front == NULL)
    {
        return false;
    }
    return true;
}