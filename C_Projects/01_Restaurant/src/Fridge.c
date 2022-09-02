#include "defines.h"
#include "Fridge.h"
#include "Dish.h"
#include <stdio.h>
#include <stdlib.h>

struct product
{
    int productAvailability;
    string productName;
};

Product *initFridge()
{
    Product *fridge = (Product *)malloc(sizeof(Product *) * 30);

    for (int i = 0; i < 36; i++)
    {
        fridge[i].productName = (string)malloc(sizeof(string));
    }

    fridge[0].productAvailability = 5;
    fridge[0].productName = "dough";

    fridge[1].productAvailability = 5;
    fridge[1].productName = "tomatoes";

    fridge[2].productAvailability = 5;
    fridge[2].productName = "cheese";

    fridge[3].productAvailability = 5;
    fridge[3].productName = "pepperoni";

    fridge[4].productAvailability = 5;
    fridge[4].productName = "bread";

    fridge[5].productAvailability = 5;
    fridge[5].productName = "ham";

    fridge[6].productAvailability = 5;
    fridge[6].productName = "bun";

    fridge[7].productAvailability = 5;
    fridge[7].productName = "chicken";

    fridge[8].productAvailability = 5;
    fridge[8].productName = "egg";

    fridge[9].productAvailability = 5;
    fridge[9].productName = "cheddar";

    fridge[10].productAvailability = 5;
    fridge[10].productName = "pickles";

    fridge[11].productAvailability = 5;
    fridge[11].productName = "lettuce";

    fridge[12].productAvailability = 5;
    fridge[12].productName = "pasta";

    fridge[13].productAvailability = 5;
    fridge[13].productName = "minced";

    fridge[14].productAvailability = 5;
    fridge[14].productName = "carrot";

    fridge[15].productAvailability = 5;
    fridge[15].productName = "onion";

    fridge[16].productAvailability = 5;
    fridge[16].productName = "rice";

    fridge[17].productAvailability = 5;
    fridge[17].productName = "corn";

    fridge[18].productAvailability = 5;
    fridge[18].productName = "peas";

    fridge[19].productAvailability = 5;
    fridge[19].productName = "cucumber";

    fridge[20].productAvailability = 5;
    fridge[20].productName = "arugula";

    fridge[21].productAvailability = 5;
    fridge[21].productName = "spinach";

    fridge[22].productAvailability = 5;
    fridge[22].productName = "quinoa";

    fridge[23].productAvailability = 5;
    fridge[23].productName = "mushrooms";

    fridge[24].productAvailability = 5;
    fridge[24].productName = "zucchini";

    fridge[25].productAvailability = 5;
    fridge[25].productName = "eggplant";

    fridge[26].productAvailability = 5;
    fridge[26].productName = "fathead";

    fridge[27].productAvailability = 5;
    fridge[27].productName = "lemon";

    fridge[28].productAvailability = 5;
    fridge[28].productName = "potatoes";

    fridge[29].productAvailability = 5;
    fridge[29].productName = "garlic";

    fridge[30].productAvailability = 5;
    fridge[30].productName = "milk";

    fridge[31].productAvailability = 5;
    fridge[31].productName = "flour";

    fridge[32].productAvailability = 5;
    fridge[32].productName = "chocolate";

    fridge[33].productAvailability = 5;
    fridge[33].productName = "ice cream";

    fridge[34].productAvailability = 5;
    fridge[34].productName = "fruits";

    fridge[35].productAvailability = 5;
    fridge[35].productName = "cream";

    return fridge;
}

string getProduct(Product *products, int n)
{
    return products[n].productName;
}

/**
 * Prints all products from fridge.
 * @param fridge  - the place where all products are
 */
void printAllFridgeProducts(Product *fridge)
{
    for (int i = 0; i < 36; i++)
    {

        printf("%d %s\n", fridge[i].productAvailability, fridge[i].productName);
    }
}

// void takeIngridientsFromFridge(product ** fridge ,Dish * dish ){
//     string* ingridientsList = getIngredientsList(dish);

//     for(int i = 0 ; i < getNumberIngredients(dish);i++){
//         for(int j = 0 ; j < 36 ; j++){
//             if(strcmp(ingridientsList[i],(*fridge[j]).productName)==0){
//                 (*fridge[j]).productAvailability--;
//             }
//         }
//     }
// }

/**
 * Empties the fridge.
 * @param fridge  - the place where all products are
 */
void freeFridge(Product *fridge)
{
    free(fridge);
}
