#ifndef _AVL_TREE_H
#define _AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    avl_tree *l, *r;
    int value;
    size_t h;
} avl_tree;

size_t get_height(avl_tree *root);
void fix_height(avl_tree *root);
int balance_factor(avl_tree *root);
avl_tree* r_rotation(avl_tree *root);
avl_tree* l_rotation(avl_tree *root);
int lower_bound(avl_tree *root, int value);
avl_tree* balance_tree(avl_tree *root);
void insert(avl_tree *root, int value);
void remove(avl_tree *root, int value);
int find_min(avl_tree *root);
int find_max(avl_tree *root);


#endif //_AVL_TREE_H