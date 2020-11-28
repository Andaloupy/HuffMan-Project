
#ifndef dictionary_h
#define dictionary_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translate.h"
/*
typedef struct Letter{
    char character;
    int occurences;

}Letter;

typedef struct Element{
    Letter* data;
    struct Element *next;

}Element;

typedef struct Element2{
    char data;
    struct Element *next;

}Element2;

typedef struct Data{
    char c;
    int occ;
}Data;

typedef struct List{
    Data *data;
    struct List *next;
}List;*/

typedef struct List{
    char c;
    int data;
    struct List *next;
}List;

typedef struct Node{
    char ch;
    int occurence;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct ListNodes{
    Node data;
    struct ListNode *next;
    struct ListNode *prev;
}ListNodes;
/*
Element* occurences(char* file);
Element* create_Element(int,char);
Element* create_Element2(char);*/
List* create_element(char c);

void print_list(List*l);

List* list_carac(char* file);

void sorted_list(List* l);
int small(List*l,int);
Node* create_huffman_tree(List*l);
int minimum(List*l);
List* delete_element(List*l,int);

Node* create_node(int val,char ch);

//void print_list(Element*);
#endif

