/**
 * \file avl.h
 * \author Sébastien Latronche
 * \brief headers to the avl.c File.
 * \date 2020-12-11
 */

#ifndef avl_h
#define avl_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
/**
 * \brief return the depth of the tree.
 * 
 * \return int 
 */
int tree_depth(Tree* tree);
/**
 * \brief return the balance factor of a tree, the difference between the depth of the right child and the left child.
 * 
 * \return int 
 */
int balance_factor(Tree* tree);
/**
 * \brief make the element do a right rotation in it's tree.
 * \return void
 */
void right_rotation(Tree** tree);
/**
 * \brief make the element do a left rotation in it's tree.
 * \return void
 */
void left_rotation(Tree** tree);
/**
 * \brief balance a tree to got a balance factor >=1.
 * \return void
 */
void balance(Tree** tree);

/**
 * \brief display a tree to the user. 
 * \return void
 */
void print_tree(Tree* tree);

#endif // avl_h
