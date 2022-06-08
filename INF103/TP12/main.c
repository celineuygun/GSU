#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<sys/time.h>
#include"heap.h"
#include"quick_sort.h"
#define SIZE 10

int main(){
    int correctarr[] = {16,14,10,8,7,9,3,2,4,1};
    int arrEx1[] = {16,4,10,14,7,9,3,2,8,1};
    max_heapify_recursive(arrEx1,1,10);
    print_heap(arrEx1,10);

    // heapify icin test durumu
    for(int i = 0; i < SIZE; i++) assert(arrEx1[i]==correctarr[i]);
    printf("Maxheapify testi gecti\n");

    int arrEx2[] = {4,1,3,2,16,9,10,14,8,7};
    build_max_heap(arrEx2,10);
    print_heap(arrEx2,10);

    // buildmaxheap icin test durumu
    for(int i = 0; i < SIZE; i++) assert(arrEx2[i]==correctarr[i]);
    printf("BuildMaxHeap testi gecti\n");

    int arrEx3[] = {4,1,3,2,16,9,10,14,8,7};
    int sorted[] = {1,2,3,4,7,8,9,10,14,16};
    heap_sort(arrEx3,SIZE);
    print_heap(arrEx3,SIZE);

    // heap Sort icin test durumu
	for(int i = 0; i < SIZE; i++) assert(arrEx3[i]==sorted[i]);
	printf("Heap Sort testi gecti\n");

    /* Zaman olcumleri icin gerekli */
    struct timeval tvBegin, tvEnd, tvDiff;

    gettimeofday(&tvBegin, NULL);
    heap_sort(arrEx3,SIZE);
	gettimeofday(&tvEnd, NULL);
    timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
    printf("heap sort (dizi boyutu : %d) --> %ld.%06ld\n", SIZE, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

    int arrEx4[] = {4,1,3,2,16,9,10,14,8,7};
    gettimeofday(&tvBegin, NULL);
    quick_sort_wrapper(arrEx4,SIZE);
	gettimeofday(&tvEnd, NULL);
    timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
    printf("quicksort (dizi boyutu : %d) --> %ld.%06ld\n", SIZE, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

    return 0;
}
