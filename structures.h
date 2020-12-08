#ifndef structures_h
#define structures_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tree{
    int poids;
    char* bit;
    char c;
    struct Tree* left;
    struct Tree* right;
}Tree;


typedef struct List{
    int data;
    char c;
    char* bits;
    struct List* next;
}List;

List* create_element(char c);
Tree* create_element_T();
#endif // structures_h
