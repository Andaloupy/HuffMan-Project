#ifndef Huffman_h
#define Huffman_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "structures.h"
#include "avl.h"



void output(char*file);
int countchar(char*file);
List* list_carac(char* file);

void print_list(List* l);
void list_remove(List** l, int n);
List* smallest(List *l);



Tree* create_huffman(List* element);
void Dico(Tree* root, char* s, FILE* dico);

void print_tree(Tree* tree);

void concatenate(char* s, char bit);
void decon(char* s);
void translate(FILE* dico, char* s);
void compress_file(char* name);

#endif // Huffman_h
