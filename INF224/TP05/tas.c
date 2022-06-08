#include "tas.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int parent(int i) {
    return (i - 1)/2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(int *arr, int k, int l) {
    int tmp = arr[k];
    arr[k] = arr[l];
    arr[l] = tmp;
}

Tas *createMaxHeap(int capacity) {
    Tas *heap = calloc(1, sizeof(Tas));
    if(!heap) exit(1);
    heap->arr = calloc(capacity, sizeof(int));
    if(!(heap->arr)) exit(1);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void deleteHeap(Tas **heap) {
    if(!(*heap)) return;
    free((*heap)->arr);
    (*heap)->arr = NULL;
    free(*heap);
    *heap = NULL;
}

void shiftUp(Tas heap, int i) {
    while(i > 0 && heap.arr[parent(i)] < heap.arr[i]) {
        swap(heap.arr, parent(i), i);
        i = parent(i);
    }
}

void shiftDown(Tas heap, int i) {
    int maxIndex = i, l = leftChild(i), r = rightChild(i);
    if(l < heap.size && heap.arr[l] > heap.arr[maxIndex])
        maxIndex = l;
    if(r < heap.size && heap.arr[r] > heap.arr[maxIndex])
        maxIndex = r;
    if(i != maxIndex) {
        swap(heap.arr, i, maxIndex);
        shiftDown(heap, maxIndex);
    }
}

void insertEleHeap(Tas **heap, int p) {
    if((*heap)->size == (*heap)->capacity) {
        printf("\nLe tableau est deja plein. Impossible d'inserer %d dans le tas.\n", p);
        return;
    } (*heap)->arr[(*heap)->size] = p;
    shiftUp(**heap, (*heap)->size);
    (*heap)->size++;
    printf("\n%d est ajoute.\n", p);
}

int getMaxHeap(Tas *heap) {
    return heap->arr[0];
}

int extractMaxHeap(Tas *heap) {
    int max = heap->arr[0];
    heap->size--;
    heap->arr[0] = heap->arr[heap->size];
    shiftDown(*heap, 0);
    return max;
}

void removeEleHeap(Tas *heap, int i) {
    if(heap) {
        if(i >= heap->size || i < 0) printf("\nL'indice %d n'est pas valable.\n", i);
        else {
            int val = heap->arr[i];
            heap->arr[i] = INT_MAX;
            shiftUp(*heap, i);
            extractMaxHeap(heap);
            printf("\n%d a supprime.\n", val);
        }
    } else printf("\nLe tas est deja vide.\n");
}

void changePriorityHeap(Tas *heap, int i, int p) {
    if(i >= heap->size || i < 0) {
        if(heap->size == heap->capacity)
            printf("\nLe tableau est deja plein. Impossible d'inserer %d dans le tas.\n", p);
        else {
            printf("\nL'indice %d n'est pas valable. Donc %d est ajoute comme un nouvel element.", i, p);
            insertEleHeap(&heap, p);
        }
    } else {
        int oldp = heap->arr[i];
        heap->arr[i] = p;
        if(p > oldp)
            shiftUp(*heap, i);
        else shiftDown(*heap, i);
    }
}

void displayHeap(Tas heap) {
    printf("\n");
    for(int i = 0; i < heap.size; ++i) {
        printf("%d ", heap.arr[i]);
    } printf("\n");
}