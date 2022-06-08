#include <stdio.h>
#include <stdlib.h>
#include "ensemble_tab.h"

int disjointSetCounterTab(int mode) {
    static int counter = 0;
    if(mode == 1) counter++;
    else if(mode == 2) counter--;
    return counter;
}


void makeSetTab(int *smallest, int i) {
    smallest[i] = i;
    disjointSetCounterTab(1);
}

int findTab(int *smallest, int i) {
    return smallest[i];
}

void unionTab(int *smallest, int size, int i, int j) {
    int idI = findTab(smallest, i), idJ = findTab(smallest, j);
    if(idI == idJ) return;
    int m = (idI < idJ) ? idI : idJ;
    for(int k = 0; k < size; ++k)
        if(smallest[k] == idI || smallest[k] == idJ)
            smallest[k] = m;
    disjointSetCounterTab(2);
}

bool areInSameSetTab(int *smallest, int i, int j) {
    return findTab(smallest, i) == findTab(smallest, j);
}

int getSizeOfSetTab(int *smallest, int size, int i) {
    int counter = 0, set = findTab(smallest, i);
    for(int j = 0; j < size; ++j) {
        if(findTab(smallest, j) == set) counter++;
    } return counter;
}

void displaySetTab(int *smallest, int size, int i) {
    int set = findTab(smallest, i);
    printf("\n{ ");
    for(int j = 0; j < size; ++j) {
        if(findTab(smallest, j) == set) {
            printf("%d ", j);
        }
    } printf("}\n");
}

void displaySmallest(int *smallest, int size) {
    printf("\n    ");
    for(int i = 0; i < size; ++i)
        printf("%-2d ", i);
    printf("  <- indexes\n  [ ");
    for(int i = 0; i < size; ++i)
        printf("%-2d ", smallest[i]);
    printf("] <- smallest\n\n");
}