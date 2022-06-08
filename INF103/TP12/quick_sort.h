#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

int partition(int *array, int low, int high);
void quick_sort(int* arr, int l, int r);
void quick_sort_wrapper(int *array, int size);

#endif /* QUICK_SORT_H_ */