#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "bst.h"
#include "matrix.h"


int main() {
    char s1[100], s2[100], filename[100];
    BStree matrix = matrix_construction();
    FILE *file;
    mark1:
    printf("please enter the file name:\n");
    scanf(" %s", filename);
    file = fopen(filename, "r");
    if(file == NULL){
        printf("error");
        goto mark1;
    }
    mark2:
    while(fscanf(file," %s" , s1)!=EOF){
        fscanf(file, " %s", s2);
        Key key = key_gen(s1, s2);
        if(*matrix == NULL){
            matrix_set(matrix,s1, s2,1);
            goto mark2;
        }
        if(matrix_isin(matrix,s1,s2) ==0){
            matrix_set(matrix,s1,s2,1);
            
        }
        else{
            matrix_inc(matrix,s1,s2,1);
        }
    }
    printf(" %s %s  %s\n","s1","s2","occur");
    matrix_list(matrix);
    matrix_destruction(matrix);
    fclose(file);
    return 0;
}


