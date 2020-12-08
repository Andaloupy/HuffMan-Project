#ifndef avl_h
#define avl_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"

int tree_depth(Tree* tree);
int balance_factor(Tree* tree);
void right_rotation(Tree** tree);
void left_rotation(Tree** tree);
void balance(Tree** tree);
void print_tree(Tree* tree);

#endif // avl_h
