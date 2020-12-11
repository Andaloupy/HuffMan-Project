/**
 * \file   structures.h
 * \brief  structures.h will stock all the structures we will use in program.  
 * \author Daiyan Costilhes daiyan.costilhes@efrei.net
 * \date   December 2020
 */
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

/**
 * \brief Function to create an element of the SLL by receiving a character from the file.
 * \n Example :
 *      \code{.c}
 *      List* list_car = create_element(c);
 *      \endcode
 * \return the list's pointer.
 */
List* create_element(char c);

/**
 * \brief Function to create an element of the huffman tree.
 * \n Example :
 *      \code{.c}
 *      Tree* new = create_element_T();
 *      \endcode
 * \return the Tree's pointer.
 */
Tree* create_element_T();
#endif // structures_h