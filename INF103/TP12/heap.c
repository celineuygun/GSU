#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"heap.h"


/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result,
                     struct timeval *t2, struct timeval *t1) {
  long int diff =
    (t2->tv_usec + 1000000 * t2->tv_sec) -
    (t1->tv_usec + 1000000 * t1->tv_sec);
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;
  return (diff < 0);
}

/*
 * Parametre olarak verilen
 * yigini ekrana basar.
 */
void print_heap(int* array, int size){
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void swap(int *intArray, int i, int j){
   int temp = intArray[i];
   intArray[i] = intArray[j];
   intArray[j] = temp;
}

/*
 * Parametre olarak verilen yiginin
 * maksimum yigin ozelligi tasimasini saglar.
 * size   : yigin boyutu
 * indeks : ozelligi bozan degerin indeksi
 */
void max_heapify_recursive(int *array, int indeks, int size){
  int l = 2 * indeks + 1, r = 2 * indeks + 2, largest = indeks;
  if(l < size && array[l] > array[indeks]) largest = l;
  if(r  < size && array[r] > array[largest]) largest = r;
  if(largest != indeks){
    swap(array, indeks, largest);
    max_heapify_recursive(array, largest, size);
  }
}


/*
 * Verilen bir diziden maksimum yigin
 * ozelliginde bir dizi olusturur.
 */
void build_max_heap(int *array, int size){
  for(int i = size / 2 - 1; i >= 0; --i){
    max_heapify_recursive(array, i, size);
  }
}

/*
 * Verilen sirasiz bir diziyi
 * yigin siralama kullanarak siralar.
 */
void heap_sort(int *array, int size){
  build_max_heap(array, size);
  swap(array, size-1, 0);
  size--;
  max_heapify_recursive(array, 1, size);
  if(size) heap_sort(array, size);
}
