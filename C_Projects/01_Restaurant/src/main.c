#include "defines.h"
#include "restaurant.h"
//!!!RUN WITH DEBUGGER!!! :( <3

int main() {
    short business = TRUE;
    while (business){
        business = openForBusiness();
    }

    return EXIT_OK;
}
