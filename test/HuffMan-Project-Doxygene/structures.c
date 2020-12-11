#include "structures.h"

Tree* create_element_T(){
    Tree* new;
    new = (Tree*)malloc(sizeof(Tree));
    new->poids = 0;
    new->left = NULL;
    new->right = NULL;
    new->c = '0';
    return new;
}

List* create_element(char c){
    List* new;
    new=(List*)malloc(sizeof(List));
    new->data = 1;
    new->c = c;
    new->next = NULL;
    new->bits = NULL;
    return new;
}

