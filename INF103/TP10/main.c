#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include"sorting.h"
#include"applications.h"
#define SIZE 20

/*
 * Rastgele dizi elemanlari uretir.
 * Dizi boyutu parametre olarak verilir.
 * Sayilar 0-100 arasindadir.
 */
void random_array(int* arrRand,int size){
   int i=0;
   srand(time(NULL));
   for(i=0;i<size;i++){
	   arrRand[i] =  rand()%100;
   }
}

int main(int argc,char* argv[]){

	int arrEx[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	int arrEx1[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	int deneme1[] = {1,2,3,7,-5,3,6,-3,4,6,-4,4,-6,3,4,7,0,8,9};
	int deneme2[] = {1,2,3,7,-5,3,6,-3,4,6,-4,4,-6,3,4,7,0,8,9};
	int deneme3[] = {1,2,3,7,-5,3,6,-3,4,6,-4,4,-6,3,4,7,0,8,9};
	int i, t, start;
	double time_taken;

	int* arrRand = malloc(sizeof(int)*SIZE);

	/*
	 * Siralama algoritmaları için test
	 */
	random_array(arrRand,SIZE);
	insertion_sort(arrRand,SIZE);
	assert(is_array_sorted(arrRand,SIZE));

	random_array(arrRand,SIZE);
	selection_sort(arrRand,SIZE);
	assert(is_array_sorted(arrRand,SIZE));

	bubble_sort(arrEx1,SIZE);
	assert(is_array_sorted(arrEx1,SIZE));

	start = clock();
	insertion_sort(deneme1, SIZE);
	t = clock() - start;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Insertion sort takes %lf second to run\n", time_taken);

	start = clock();
	selection_sort(deneme2, SIZE);
	t = clock() - start;
	time_taken = ((double)t)/CLOCKS_PER_SEC;	
	printf("Selection sort takes %lf second to run\n", time_taken);

	start = clock();
	bubble_sort(deneme3, SIZE);
	t = clock() - start;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Bubble sort takes %lf second to run\n", time_taken);

	// Sirali dizi ile maksimum testi
	assert(find_maxsum_elements_sorted(arrEx1,SIZE)==146);
	// Sirasiz dizi ile maksimum testi
	assert(find_maxsum_elements_unsorted(arrEx,SIZE)==146);

	// Mod elemani bulan fonksiyon testi
	int arrMode[] = {3,4,6,1,3,4,3,1,3,6};
	assert(find_mode_element(arrMode,10)==3);

	// minimum 5 eleman testi
	int arrRes[] = {0,0,0,0,0};
	int arrEx5[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	minimum_k_elements(arrEx5,SIZE,5,arrRes);
	for(i=0;i<5;i++){
		assert(arrRes[i]==arrEx5[i]);
	}

	//remove_duplications testi
	int arrDup[] = {3,4,6,1,3,2,3,1,3,6};
	int* dest;
	remove_duplications(arrDup,10,dest);
	for(i = 1; i < 5; i++){
		assert(dest[i-1]!=dest[i]);
	}
	
	return 0;
}
