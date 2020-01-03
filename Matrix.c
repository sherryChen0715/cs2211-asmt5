//
// Created by tamaki on 2018/12/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "bst.h"
#include "matrix.h"
/**
 * Matrix construction using bstree ini();
 * @return
 */
Matrix matrix_construction(void){
    Matrix new_matrix = (Matrix) bstree_ini();
    return new_matrix;
}
/**
 * If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0
 * @param m
 * @param index1
 * @param index2
 * @return
 */
unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Data search = bstree_search(m,key_gen(index1,index2));
    if(search == NULL){
        return 0;
    }
    else{
        return 1;
    }
}
/**
 * If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
value. Otherwise, return NULL.
 * @param m
 * @param index1
 * @param index2
 * @return
 */
Value *matrix_get(Matrix m, Index index1, Index index2){
    return bstree_search(m,key_gen(index1,index2));
}
/**
 * Assign value to Matrix m at location (index1, index2). If that location already has value,
then overwrite.
 * @param m
 * @param index1
 * @param index2
 * @param value
 */
void matrix_set(Matrix m, Index index1, Index index2, Value value){
    if(*m==NULL){
        bstree_insert(m,key_gen(index1,index2),data_gen(value));
    }
    else{
        Data result = bstree_search(m,key_gen(index1,index2));
        if(result==NULL){
            bstree_insert(m,key_gen(index1,index2),data_gen(value));
        }
        else{
            *result=value;
        }
    }
}
/**
 * If location (index1, index2) is defined in Matrix m, then increase the associated value by
value. Otherwise, report error.
 * @param m
 * @param index1
 * @param index2
 * @param value
 */
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    Data result = bstree_search(m,key_gen(index1,index2));
    if(result==NULL){
        printf("Error in matrix_inc");
        exit(EXIT_FAILURE);
    }
    else{
        *result=value+*result;
    }
}
/**
 * Print indices and values in the Matrix m (with bstree traversal()).
 * @param m
 */
void matrix_list(Matrix m){
    bstree_traversal(m);
}
/**
 * Free allocated space (with bstree free()).
 * @param m
 */
void matrix_destruction(Matrix m){
    bstree_free(m);
}

