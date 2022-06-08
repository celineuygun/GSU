#include <stdlib.h>
#include"heap.h"

int partition(int *array, int low, int high) {
    int i = low - 1, j, pivot = array[high];
    for(j = low; j < high; ++j){
        if(array[j] < pivot){
            ++i;
            swap(array, i, j);
        }
    }swap(array, i + 1, high);
    return (i + 1);
}

void quick_sort(int* arr, int l, int r){
    if(l >= r) return;
    int p = partition(arr, l, r); // position of the pivot
    quick_sort(arr, l, p-1); // left side
    quick_sort(arr, p+1, r); // right side
}

void quick_sort_wrapper(int *array, int size){
  quick_sort(array, 0, size - 1);
}