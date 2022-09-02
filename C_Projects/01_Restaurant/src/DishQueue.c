#include "..\include\DishQueue.h"
#include "Dish.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct queueNode
{
    Dish *dish;
    struct queueNode *next;
};

struct queue
{
    struct queueNode *front;
    struct queueNode *rear;
};

dishQueue *initDishQueue()
{
    dishQueue *dQueue = (dishQueue *)malloc(sizeof(dishQueue));
    dQueue->front = NULL;
    dQueue->rear = NULL;
    return dQueue;
}

/**
 * Add dish to queue.
 * @param dish - the dish that has to be add to queue 
 * @param dishQueue  - the queue where we add dish
 */
void enQueueDish(Dish *dish, dishQueue *dishQueue)
{
    dishNode *node = (dishNode *)malloc(sizeof(dishNode));

    node->dish = dish;
    node->next = NULL;

    if (dishQueue->front == NULL)
    {
        dishQueue->front = node;
        dishQueue->rear = node;
        return;
    }
    dishQueue->rear->next = node;
    dishQueue->rear = node;
}

Dish *deQueueDish(dishQueue *current)
{
    dishNode *elToDeQueue = current->front;
    if (current->front == NULL)
    {
        printf("List of dishes is empty !!!");
        return NULL;
    }
    if (current->front == current->rear)
    {
        current->front = current->rear = NULL;
        Dish *temp = elToDeQueue->dish;
        free(elToDeQueue);
        return temp;
    }
    Dish *temp = elToDeQueue->dish;
    current->front = current->front->next;
    free(elToDeQueue);
    return temp;
}

bool isEmptyDish(dishQueue *dishQueue)
{
    if (dishQueue->front == NULL)
    {
        return false;
    }
    return true;
}

dishQueue *fillDishQ(Dish **menuu, Table **allTables)
{
    dishQueue *dishQ = initDishQueue();
    for (int i = 0; i<8; i++)
    {
        if(!getIsFree(allTables[i])){
        enQueueDish(GetDishFromId(menuu, getDishMenuID(getCustomer(allTables[i])), getTable(allTables[i])), dishQ);
        }
    }
    return dishQ;
}

/**
 * Print the queue from dishs.
 * @param dishQueue  - the queue that has to be print
 */
void printDishQueue(dishQueue *dishQ)
{
    dishNode *temp = dishQ->front;
    for (int client_number = 0; temp != NULL; client_number++)
    {
        printf("On table %d \nDish name: %s \nMenu ID : %d \n\n", getTableNumber(getDishTable(temp->dish)), getDishName(temp->dish), getMenuID(temp->dish));
        temp = temp->next;
    }
}