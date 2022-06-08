#include <stdlib.h>

void merge(int *array, int low, int middle, int high) {
  int i, j, k;
  int l_size = middle - low + 1;
  int r_size = high - middle ;
  int* L = malloc(l_size * sizeof(int));
  int* R = malloc(r_size * sizeof(int));
  for(i = 0; i < l_size; ++i) L[i] = array[low + i];
  for(i = 0; i < r_size; ++i) R[i] = array[middle + i + 1];

  for(i = 0, j = 0, k = low; i < l_size && j < r_size; ++k){
    if(L[i] <= R[j]){
      array[k] = L[i];
      ++i;
    }
    else{
      array[k] = R[j];
      ++j;
    }
  }
  while(i < l_size){
    array[k] = L[i];
    ++i;
    ++k;
  }
  while(j < r_size){
    array[k] = R[j];
    ++j;
    ++k;
  }
  free(L);
  free(R);
}

/* Bolme ve birlestirme metodunu gerceklestiren fonksiyon */
void merge_sort(int *array, int low, int high) {
  if (low < high) {
    int middle = (low + high)/2;
    merge_sort(array, low, middle);
    merge_sort(array, middle + 1, high);
    merge(array, low, middle, high);
  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size - 1);
}
