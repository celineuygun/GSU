#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arr.h"

ArrDy *createArrDy(int capacity) {
    ArrDy *new = calloc(1, sizeof(ArrDy));
    if(new) {
        new->capacity = capacity;
        new->size = 0;
        new->arr = calloc(capacity, sizeof(int));
        if(!new->arr) exit(1);
    } return new;
}

void deleteArrDy(ArrDy **arrDy) {
    free((*arrDy)->arr);
    free(*arrDy);
    *arrDy = NULL;
}

int get(ArrDy *arrDy, int i) {
    if(!arrDy) printf("\nLe tableau dynamique est vide.\n");
    else if(i < 0 || i >= arrDy->size) printf("\nL'indice %d n'est pas valable.\n", i);
    else return arrDy->arr[i];
    return -1;
}

void set(ArrDy *arrDy, int i, int val) {
    if(!arrDy) printf("\nLe tableau dynamique est vide.\n");
    else if(i < 0 || i >= arrDy->size) printf("\nL'indice %d n'est pas valable.\n", i);
    else arrDy->arr[i] = val;
}

void pushBack(ArrDy **arrDy, int val) {
    if(!(*arrDy)) {
        (*arrDy) = createArrDy(10);
    } else if((*arrDy)->size == (*arrDy)->capacity) {
        ArrDy *tmp = createArrDy(2 * (*arrDy)->capacity);
        for(int i = 0; i < (*arrDy)->size; ++i) tmp->arr[i] = (*arrDy)->arr[i];
        free((*arrDy)->arr);
        (*arrDy)->capacity *= 2;
        (*arrDy)->arr = tmp->arr;
        free(tmp);
    } (*arrDy)->arr[(*arrDy)->size++] = val;
}

int removeItem(ArrDy *arrDy, int i) {
    if(!arrDy) printf("\nLe tableau dynamique est deja vide.\n");
    else if(i < 0 || i >= arrDy->size) printf("\nL'indice %d n'est pas valable.\n", i);
    else {
        int retVal = arrDy->arr[i];
        for(int j = i; j < arrDy->size - 1; ++j) arrDy->arr[j] = arrDy->arr[j + 1];
        arrDy->size--;
        printf("\n%d est suprime\n", retVal);
        return retVal;
    } return -1;
}

int getSize(ArrDy *arrDy) {
    return arrDy->size;
}

int getCapacity(ArrDy *arrDy) {
    return arrDy->capacity;
}

void printArrDy(ArrDy *arrDy) {
    if(!arrDy) {
        printf("\nLe tableau dynamique est vide.\n");
        return;
    } for(int i = 0; i < arrDy->size; ++i) printf("%d ", arrDy->arr[i]);
    printf("]\n");
}