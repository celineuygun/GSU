#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

typedef struct DynamicArray {
    int capacity;
    int size;
    int *arr;
} ArrDy;

ArrDy *createArrDy(int capacity);
void deleteArrDy(ArrDy **arrDy);
int get(ArrDy *arrDy, int i);
void set(ArrDy *arrDy, int i, int val);
void pushBack(ArrDy **arrDy, int val);
int removeItem(ArrDy *arrDy, int i);
int getSize(ArrDy *arrDy);
int getCapacity(ArrDy *arrDy);
void printArrDy(ArrDy *arrDy);

#endif