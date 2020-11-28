#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"



int main(){
    int test;



    output("Alice.txt");
    test = countchar("Alice.txt");
    printf("%d\n",test);
    test = countchar("Output.txt");
    printf("%d\n",test);
    List* list_car = (List*)malloc(sizeof(List));

    list_car = list_carac("Alice.txt");


    print_list(list_car);
    list_car = delete_element(list_car,minimum(list_car));
     print_list(list_car);
     //remove_element(&list_car,minimum(list_car));
    //printf("%d\n",minimum(list_car));
   // sorted_list(list_car);

    return 0;


}
