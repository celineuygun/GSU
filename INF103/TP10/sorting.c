#include"sorting.h"

/*
 * Parametre olarak verilen dizide
 * i ve j indexlerinde bulunan
 * elemanlarin yerlerini degistirir.
 */
void swap(int* arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/*
 * Insertion sort icerisinde sirali kisma
 * yerlestirecegimiz elemanin gelmesi gereken
 * indexi geri dondurecek binary search fonksiyonu
 */
int binary_s_for_isort(int* arr, int l, int r, int n){
    if(r > l){
        int m = (l + r) / 2;
        if(arr[m] == n) return m + 1;
        else if(arr[m] < n) return binary_s_for_isort(arr, m + 1, r, n);
        else return binary_s_for_isort(arr, l, m -1, n);
    }return (n > arr[l]) ? l + 1 : l;
}

/*
 * Binary insertion sort
 * Parametre olarak verilen dizi elemanlarini
 * insertion sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 */
void insertion_sort(int* arritem, int size){
	for(int i = 1; i < size; ++i){
        int j = i - 1, selected = arritem[i]; 
        int loc = binary_s_for_isort(arritem, 0, i-1, arritem[i]);
        while(j >= loc){
            arritem[j+1] = arritem[j];
            j--;
        }arritem[j+1] = selected;
    }
}


/*
 * Parametre olarak verilen diziyi
 * selection_sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 */
void selection_sort(int* arritem, int size){
    for(int i = 0; i < size - 1; ++i){
        int min = i;
        for(int j = i + 1; j < size; ++j){ 
            if(arritem[j] < arritem[min]) min = j;
        }if(min != i) swap(arritem, i, min);
    }
}

/*
 * Parametre olarak verilen diziyi
 * kabarcik siralamasi (bubble sort)
 * kullarak siralar.
 * Sirali dizi olarak donus yapar.
 */
void bubble_sort(int* arritem, int size){
    for(int i = size; i >= 2; --i){
        int flag = 0;
        for(int j = 0; j < i - 1; ++j){
            if(arritem[j] > arritem[j+1]){
                swap(arritem, j, j+1);
                flag = 1;
            }
        }
        if(!flag) break;
    }
}
