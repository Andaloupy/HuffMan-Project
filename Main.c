#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"
#include <string.h>

int main(){
    FILE* dico = NULL;
    dico = fopen("dico.txt", "w+");
    int test;
    output("Alice.txt");
    test = countchar("Alice.txt");
    printf("%d\n",test);
    test = countchar("Output.txt");
    printf("%d\n",test);

    List* list_car;
    list_car = list_carac("Alice.txt");

    List* sorted_list, *temp;
    sorted_list = smallest(list_car);
    list_remove((&list_car), sorted_list->data);
    temp = sorted_list;
    while (list_car->next != NULL){
        temp->next = smallest(list_car);
        list_remove((&list_car), temp->next->data);
        temp = temp->next;
    }
    temp->next = list_car; 
    list_remove((&list_car), temp->data);
    print_list(sorted_list);

    Tree* root;
    char* s = malloc(sizeof(*s)*16);
    s[0]='\0'; 
    root = create_huffman(sorted_list);
    printf("%d\n", root->poids);

    balance(&root);
    Dico(root,s,dico);
    printf("%d\n", root->poids);
    print_tree(root);
    free(s);
    return 0;
}