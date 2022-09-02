#ifndef GROUP_TASK_RESTAURANT_CUSTOMER_H
#define GROUP_TASK_RESTAURANT_CUSTOMER_H

typedef struct customer Customer;
Customer *newCustomer(void);

int getNumberOfOrder(Customer *customer);
int getDishMenuID(Customer *customer);

#endif
