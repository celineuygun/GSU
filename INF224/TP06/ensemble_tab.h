#ifndef ENSEMBLE_TAB_H
#define ENSEMBLE_TAB_H
#include <stdbool.h>
#include "dynamic_arr.h"

int disjointSetCounterTab(int mode);
void makeSetTab(int *smallest, int i);
int findTab(int *smallest, int i);
void unionTab(int *smallest, int size, int i, int j);
bool areInSameSetTab(int *smallest, int i, int j);
int getNumElementTab(int *smallest);
int getSizeOfSetTab(int *smallest, int size, int i);
void displaySetTab(int *smallest, int size, int i);
void displaySmallest(int *smallest, int size);

#endif