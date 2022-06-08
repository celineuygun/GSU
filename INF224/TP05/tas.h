#ifndef TAS_H_
#define TAS_H_

typedef struct maxHeap {
    int capacity;
    int size;
    int *arr;
} Tas;

int parent(int i);
int leftChild(int i);
int rightChild(int i);
void swap(int *arr, int k, int l);
Tas *createMaxHeap(int capacity);
void deleteHeap(Tas **heap);
void shiftUp(Tas heap, int i);
void shiftDown(Tas heap, int i);
void insertEleHeap(Tas **heap, int p);
int getMaxHeap(Tas *heap);
int extractMaxHeap(Tas *heap);
void removeEleHeap(Tas *heap, int i);
void changePriorityHeap(Tas *heap, int i, int p);
void displayHeap(Tas heap);

#endif