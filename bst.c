//
// Created by tamaki on 2018/11/30.
//

#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "datatype.h"
/**
 * Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the
allocated memory.
 * @return
 */
BStree bstree_ini(void){
    BStree bst = (BStree)malloc(sizeof(BStree_node));
    *bst = NULL;
    return bst;
}
/**
 * Insert data with key into bst. If key is in bst, then do nothing.
 * @param bst
 * @param key
 * @param data
 */
void bstree_insert(BStree bst, Key key, Data data){

    if(*bst==NULL){
        *bst=new_node(key,data);
    }
    else{
        if(key_comp((*bst)->key,key)<0){ //smaller key go left
            bstree_insert(&(*bst)->right,key,data);
        }
        else if(key_comp((*bst)->key,key)>0){
            bstree_insert(&(*bst)->left,key,data);
        }
    }

}
/**
 * create a new node
 * @param key
 * @param data
 * @return
 */
BStree_node *new_node(Key key, Data data){
    BStree_node* node=(BStree_node *)malloc(sizeof(BStree_node));
    node->data=data;
    node->key=key;
    node->right=NULL;
    node->left=NULL;
    return node;
}
/**
 *If key is in bst, return key’s associated data. If key is not in bst, return NULL.
 * @param bst
 * @param key
 * @return
 */
Data bstree_search(BStree bst, Key key){
    bst_searchsearch(*bst,key);
}
/**
 * helper method for search
 * @param bst
 * @param key
 * @return
 */
Data bst_searchsearch(BStree_node *bst, Key key){
    if ( bst == NULL ) {
        return NULL;
    }
    else{
        if(key_comp(key, bst->key)<0){
            return bst_searchsearch(bst->left,key);
        }
        else if(key_comp(key, bst->key)>0) {
            return bst_searchsearch(bst->right, key);
        }
        else{
            return bst->data;
        }
    }
}
/**
 * In order traversal of bst and print each node’s key and data.
 * @param bst
 */
void bstree_traversal(BStree bst){
    bst_traversaltraversal(*bst);
}
/**
 * helper method for travesal
 * @param bst
 */
void bst_traversaltraversal(BStree_node *bst){
    if(bst !=NULL){
        bst_traversaltraversal(bst->left);
        key_print(bst->key);
        data_print(bst->data);
        bst_traversaltraversal(bst->right);
    }
}
/**
 * Free all the dynamically allocated memory of bst.
 * @param bst 
 */
void bstree_free(BStree bst){
    if((*bst) != NULL){
        bstree_free(&(*bst)->left);
        key_free((*bst)->key);
        data_free((*bst)->data);
        bstree_free(&(*bst)->right);
    }
}
