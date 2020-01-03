//
// Created by tamaki on 2018/11/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

/**
 * Duplicate string pointed to by str with dynamic memory allocation.
 * @param str
 * @return
 */
char * string_dup(char *str){
    char * copy = (char*) malloc((strlen(str)+1)* sizeof(char));
    if(copy == NULL){
        printf("Error");
        exit(EXIT_FAILURE);
    }
    else{
        strcpy(copy,str);
        return copy;
    }
}
/**
 * Generate a key with dynamic memory allocation.
 * @param skey1
 * @param skey2
 * @return
 */
Key key_gen(char *skey1, char *skey2){
    Key new_key = (Key) malloc(sizeof(Key_struct));
    if(new_key == NULL){
        printf("Error in key gen");
        exit(EXIT_FAILURE);
    }
    else{
        new_key->skey1 = string_dup(skey1);
        new_key->skey2 = string_dup(skey2);
        return new_key;
    }
}
/**
 * Use strcmp( ) to do comparison
 * @param key1
 * @param key2
 * @return
 */
int key_comp(Key key1, Key key2){
    if(strcmp(key1->skey1 ,key2->skey1)!=0){ //If key1->skey1 and key2->skey1 are different, then they determine the comparison result.
        return strcmp(key1->skey1 ,key2->skey1);
    }
    else{// If key1->skey1 and key2->skey1 are the same,then key1->skey2 and key2->skey2 determine the comparison result.
        return strcmp(key1->skey2,key2->skey2);
    }
}
/**
 * Print a key.
 * @param key
 */
void key_print(Key key){
    printf("%s %s", key->skey1,key->skey2);
}
/**
 * Free memory allocated for key.
 * @param key
 */
void key_free(Key key){ //Free memory allocated for key.
    free(key->skey1);
    free(key->skey2);
    free(key);

}
/**
 * Generate a data with dynamic memory allocation.
 * @param idata
 * @return
 */
Data data_gen(int idata){ //Generate a data with dynamic memory allocation.
    Data new_data = (Data)malloc(sizeof(int));
    if(new_data == NULL){
        printf("Error in data gen");
        exit(EXIT_FAILURE);
    }
    else{
        data_set(new_data,idata);
        return new_data;
    }
}
/**
 *Assign data with idata.
 * @param data
 * @param idata
 */
void data_set(Data data, int idata){
    *data = idata;
}
/**
 * Print a data.
 * @param data
 */
void data_print(Data data){
    printf(" %d\n",*data);
}
/**
 * Free memory allocated for data
 * @param data
 */
void data_free(Data data){
    free(data);
}
