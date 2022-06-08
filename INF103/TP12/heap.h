#ifndef HEAP_H_
#define HEAP_H_

int timeval_subtract(struct timeval *result,
                     struct timeval *t2, struct timeval *t1);
void swap(int *intArray, int i, int j);
void print_heap(int* array,int size);
void max_heapify_recursive(int *array,int indeks,int size);
void build_max_heap(int *array,int size);
void heap_sort(int *array, int size);

#endif /* HEAP_H_ */
