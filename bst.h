//
// Created by tamaki on 2018/11/30.
//
#include "datatype.h"
#ifndef UNTITLED3_BST_H
#define UNTITLED3_BST_H
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;
BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void bst_insertinsert(BStree_node *bst,Key key, Data data);
Data bst_searchsearch(BStree_node *bst, Key key);
void bst_traversaltraversal(BStree_node *bst);
#endif //UNTITLED3_BST_H

