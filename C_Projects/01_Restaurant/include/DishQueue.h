#ifndef GROUP_TASK_RESTAURANT_DISHQUEUE_H
#define GROUP_TASK_RESTAURANT_DISHQUEUE_H
#include"Dish.h"
#include<stdbool.h>

typedef struct queueNode dishNode;
typedef struct queue dishQueue;

dishQueue * initDishQueue();
void enQueueDish(Dish * dish,dishQueue * dishQueue);
Dish * deQueueDish(dishQueue * current);
bool isEmptyDish(dishQueue *dishQueue);
dishQueue *fillDishQ(Dish **menuu, Table **allTables);
void printDishQueue(dishQueue *dishQ);
#endif