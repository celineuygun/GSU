#ifndef ENSEMBLE_LL_H
#define ENSEMBLE_LL_H
#include <stdbool.h>

struct SetPointer;

typedef struct DisjointSetLl {
    int data;
    struct DisjointSetLl *next;
    struct SetPointer *ptr;
} SetLl;

typedef struct SetPointer {
    SetLl *head;
    SetLl *tail;
} SetPtr;

int disjointSetCounterLl(int mode);
SetPtr *makeSetLl(int elemNum);
void deleteSetsLl(SetPtr ***sets, int size);
bool areInSameSetLl(SetPtr **sets, int k, int l);
void mergeSetsLl(SetPtr **sets, int k, int l);
int getSizeOfSetLl(SetPtr *set);
void displaySetLl(SetPtr *set);
void displaySetsLl(SetPtr **sets, int elemNum);

#endif