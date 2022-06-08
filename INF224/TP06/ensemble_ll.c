#include <stdio.h>
#include <stdlib.h>
#include "ensemble_ll.h"

int disjointSetCounterLl(int mode) {
    static int counter = 0;
    if(mode == 1) counter++;
    else if(mode == 2) counter--;
    return counter;
}

SetPtr *makeSetLl(int data) {
    SetPtr *new = calloc(1, sizeof(SetPtr));
    if(new) {
        new->head = calloc(1, sizeof(SetLl));
        new->tail = new->head;
        new->head->data = data;
        new->head->next = NULL;
        new->head->ptr = new;
        disjointSetCounterLl(1);
    } return new;
}

void deleteSetsLl(SetPtr ***sets, int size) {
    if(**sets) {
        SetPtr **setTmp = *sets, **deleted= calloc(size, sizeof(SetPtr *));
        for(int i = 0, k = 0; i < size; ++i) {
            int flag = 1;
            for(int j = 0; j < k; ++j)
                if(deleted[j] == setTmp[i]) {
                    flag = 0;
                    break;
                }
            if(flag) {
                SetLl *tmp = setTmp[i]->head, *cur = NULL;
                while(tmp) {
                    cur = tmp;
                    tmp = tmp->next;
                    free(cur);
                } deleted[k] = setTmp[i];
                ++k;
            }
        } free(deleted);
    }
}

bool areInSameSetLl(SetPtr **sets, int k, int l) {
    if(sets && sets[k] && sets[l]) return sets[k] == sets[l];
    return false;
}

void mergeSetsLl(SetPtr **sets, int k, int l) {
    if(!areInSameSetLl(sets, k, l)) {
        sets[k]->tail->next = sets[l]->head;
        sets[k]->tail = sets[l]->tail;
        for(SetLl *tmp = sets[l]->head; tmp != NULL; tmp = tmp->next) {
            sets[tmp->data] = sets[k];
            tmp->ptr = sets[k];
        } disjointSetCounterLl(2);
    }
}

int getSizeOfSetLl(SetPtr *set) {
    if(!set) return -1;
    int num = 0;
    for(SetLl *tmp = set->head; tmp != NULL; tmp = tmp->next) num++;
    return num;
}

void displaySetLl(SetPtr *set) {
    if(!set) {
        printf("\nL'ensemble est vide.\n");
        return;
    } printf("{ "); 
    for(SetLl *tmp = set->head; tmp != NULL; tmp = tmp->next) printf("%d ", tmp->data);
    printf("} ");
}

void displaySetsLl(SetPtr **sets, int elemNum) {
    printf("\n");
    SetPtr **printed= calloc(elemNum, sizeof(SetPtr *));
    for(int i = 0, k = 0; i < elemNum; ++i) {
        int flag = 1;
        for(int j = 0; j < k; ++j)
            if(printed[j] == sets[i]) {
                flag = 0;
                break;
            }
        if(flag) {
            displaySetLl(sets[i]);
            printed[k] = sets[i];
            ++k;
            continue;
        }
    } printf("\n");
    free(printed);
}