#ifndef GROUP_TASK_RESTAURANT_FRIDGE_H
#define GROUP_TASK_RESTAURANT_FRIDGE_H

typedef struct product Product;
Product * initFridge();
//void takeIngridientsFromFridge(product ** fridge, Dish * dish );
void freeFridge(Product*fridge);
string getProduct(Product * product,int n);
void printAllFridgeProducts(Product * fridge);

#endif //GROUP_TASK_RESTAURANT_FRIDGE_H