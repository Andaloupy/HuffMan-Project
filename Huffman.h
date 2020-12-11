/**
 * \file Huffman.h
 * \author Sébastien Latronche 
 * \brief It's the header for the huffman.c file, the function.
 * \date 2020-12-11
 * 
 */

#ifndef Huffman_h
#define Huffman_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "structures.h"
#include "avl.h"


/**
 * \brief Function to translate a .txt in binary. 
 *      \n Example :
 *       \code{.c}
 *       output(Texte.txt);
 *       \endcode 
 * \return nothing
 * 
 * \param file 
 */
void output(char*file);

/**
 * \brief return the number of character in a .txt file.
 *      \n Example ;
 *       \code{.c}
 *       int nb_char = countchar(Texte.txt);
 *       \endcode
 * 
 * \param file 
 * \return int 
 */
int countchar(char*file);

/**
 * \brief return a pointer to the list, and create a linked list with all the characers present in the file and their nb of occurence.
 *      \n Example :
 *       \code{.c}
 *       List* list_char = list_carac(Texte.txt);
 *       \endcode
 * 
 * 
 * \param file 
 * \return List* 
 */
List* list_carac(char* file);

/**
 * \brief display a list to the user.
 * 
 * \param l
 * \return void
 */
void print_list(List* l);
/**
 * \brief display a tree to the user.
 * 
 * \param tree
 * \return void
 */
void print_tree(Tree* tree);


/**
 * \brief remove an element from a list, here depending on n, a number.
 *      \n Example :
 *       \code{.c}
 *       list_remove(list_charac, 1);
 *       \endcode
 * 
 * \return void
 */
void list_remove(List** l, int n);

/**
 * \brief Find and return the smallest element of a list.
 *      \n Example :
 *       \code{.c}
 *       List* exemple = smallest(list_char);
 *       \endcode
 * 
 * \return List* 
 */
List* smallest(List *l);


/**
 * \brief Create a huffman tree from a list.
 *      \n Example :
 *       \code{.c}
 *       \Tree* root = create_huffman(list_char);
 *       \endcode
 *  
 * \return Tree* 
 */
Tree* create_huffman(List* element);

/**
 * \brief create a dictionnary.txt File to compress the .txt from the Huffman tree.
 * \return void
 */
void Dico(Tree* root, char* s, FILE* dico);

/**
 * \brief Function to concatenate a string with a character.
 * \return void
 */
void concatenate(char* s, char bit);
/**
 * \brief Function to remove the last character of a string.
 * \return void
 */
void decon(char* s);
/**
 * \brief Function that compress a .txt thanks to the dictionnary.
 * \return void
 */
void translate(FILE* dico, char* s);

/**
 * \brief Do all the necessary step to compress a .txt file.
 * \return void
 */
void compress_file(char* name);

#endif // Huffman_h
