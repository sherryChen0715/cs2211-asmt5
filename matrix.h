//
// Created by tamaki on 2018/12/2.
//
#include "bst.h"
#ifndef UNTITLED3_MATRIX_H
#define UNTITLED3_MATRIX_H
typedef BStree Matrix;
typedef char* Index;
typedef int Value;
Matrix matrix_construction(void);
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
Value *matrix_get(Matrix m, Index index1, Index index2);
void matrix_set(Matrix m, Index index1, Index index2, Value value);
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);
#endif //UNTITLED3_MATRIX_H


