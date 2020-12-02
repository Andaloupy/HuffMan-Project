#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int data;
    char c;
    struct List* next;
}List; 

void output(char*file);
int countchar(char*file);
List* list_carac(char* file);
List* create_element(char c);
void print_list(List* l);
void list_remove(List** l, int n);
List* smallest(List *l);

typedef struct Tree{
    int poids;
    char c;
    struct Tree* left;
    struct Tree* right;
}Tree;

Tree* create_element_T();
Tree* create_huffman(List* element);
void Dico(Tree* root);

