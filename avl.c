#include "avl.h"


int tree_depth(Tree* tree){
    if (tree == NULL){
        return 0;
    }
    else{
        int dl = tree_depth(tree->left);
        int dr = tree_depth(tree->right);

        if (dl > dr){
            return dl + 1;
        }
        else{
            return dr + 1;
        }
    }
}

int bf(Tree* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        return tree_depth(tree->right) - tree_depth(tree->left);
    }
}

void right_rotation(Tree** tree){
    if(*tree != NULL){
        Tree* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Tree** tree){
    if(*tree != NULL){
        Tree* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

void balance(Tree** tree){
    if (*tree != NULL){
        balance(&((*tree)->left));
        balance(&((*tree)->right));

        int balance_factor = bf(*tree);
        if(balance_factor <= -2){//Left - ????
            if(bf((*tree)->left) > 0){// Left - Right
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Left-Left
        }
        else if(balance_factor >= 2){//Right - ????
            if(bf((*tree)->right) < 0){// Right - Left
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Right-Right
        }
    }
}
