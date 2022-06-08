#include "applications.h"
#include "sorting.h"

/* Parametre olarak verilen dizinin sirali
 * olmadigini kontrol eder.
 * Dizi sirali ise 1, degilse 0 doner.
 */
int is_array_sorted(int* arritem,int size){
    int i=0;
	while(i < size-1){
		if(arritem[i] > arritem[i+1]) return 0;
		i++;
	}return 1;
}

/*
 * Sirasiz verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {4,5,8,2,10}
 *        sonuce = 18
 */
int find_maxsum_elements_unsorted(int* arritem,int size){
    insertion_sort(arritem, size);
	int maxsum = arritem[size-1] + arritem[size-2];
	return maxsum;
}

/*
 * Sirali verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {2,4,5,8,10}
 *        sonuce = 18
 */
int find_maxsum_elements_sorted(int* arritem,int size){
    insertion_sort(arritem, size);
	int maxsum = arritem[size-1] + arritem[size-2];
	return maxsum;
}

/*
 * Parametre olarak verilen dizide en cok
 * bulunan elemani(mode) geri dondurur.
 * Ornek: dizi = {2,3,6,1,3,1,4,3}
 *        sonuc = 3
 */
int find_mode_element(int* arritem,int size){
	int mode = 1, counter, max = 0;
	insertion_sort(arritem, size);
	for(int i = 0; i < size - 1; ++i){
		counter = 0;
		while(arritem[i] == arritem[i+1]){++counter; ++i;}
		if(max <= counter){max = counter + 1; mode = arritem[i-1];}
	}
	return mode;
}

/*
 * Parametre olarak verilen dizide elemanlardan
 * minimum k tanesini gonderir.
 * arritem: parametre olarak verilen dizi
 *   size : dizi boyutu
 *     k  : en kucuk kac eleman
 *  arrRes: en kucuk k elemani tasiyan dizi
 * Ornek: dizi={2,1,6,9,4,7}
 *        en kucuk 3 eleman: {1,2,4}
 */
void minimum_k_elements(int* arritem,int size,int k,int arrRes[k]){
	insertion_sort(arritem, size);
	for(int i = 0; i < k; ++i){
		arrRes[i] = arritem[i];
	}
}

/*
 * Parametre olarak verilen bir diziden yeni bir dizi
 * olusturur. Yeni dizi tekrar eden sayilari icermez.
 * Diger sayilar da sirali olarak dizilir.
 * arritem : ayni elemanlari iceren dizi
 *    size : dizinin eleman sayisi
 *    dest : sonucta olusan dizi
 * Ornek: dizi = {2,3,5,1,7,2,3,5}
 *        sonuc= {1,2,3,5,7}
 */
void remove_duplications(int* arritem,int size,int* dest){
	insertion_sort(arritem, size);
	for(int i = 0, j = 0; i < size - 1; ++i, ++j){
		dest[j] = arritem[i];
		while(arritem[i] == arritem[i+1]) ++i;
	}
}