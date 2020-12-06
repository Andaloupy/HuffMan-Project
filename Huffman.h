#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



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
void Dico(Tree* root, char* s, FILE* dico);
int tree_depth(Tree* tree);
int bf(Tree* tree);
void right_rotation(Tree** tree);
void left_rotation(Tree** tree);
void balance(Tree** tree);
void print_tree(Tree* tree);

void concatenate(char* s, char bit);
void decon(char* s);
void translate(FILE* dico, char* s);
void compress_file(char* name);