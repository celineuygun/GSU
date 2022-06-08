/*
 * main.c
 *
 *      Author: Selin Uygun
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define A 150 // Hesaplanacak sensor degeri sayisi
#define ALT 10  // Sensor deger araliginin alt degeri
#define UST 50  // Sensor deger araliginin ust degeri
#define N 6
#define AR 12 // Histogram icin aralik sayisi

float min(float[]);
float max(float[]);
float mean(float[]);
float std_sapma(float[]);
int max_int(int[], size_t); 

int main(){
    printf("———————————————————————————————————————————————————————————————————————\n");
    printf("************************** SENSOR DEGERLERI: **************************\n");
    printf("———————————————————————————————————————————————————————————————————————\n");
    
    float array[A];
    float somme = 0;
    
    srand(time(0));
 
    for(int i = 0 ; i < A ; i++) {
        for(int j = 0; j < N; j++){       
            array[i] = ALT + rand() % (UST-ALT+1);  
            somme += array[i];  
        }
        array[i] = somme/N;
        somme = 0; 
    }

    for(int k = 0; k < A; k++){
        printf("%.2f\n", array[k]);
    }

    printf("———————————————————————————————————————————————————————————————————————\n");
    printf("************************ OLCUM ISTATISTIKLERI: ************************\n");
    printf("———————————————————————————————————————————————————————————————————————\n");
    
    printf("Min: %.2f\n", min(array));
    printf("Max: %.2f\n", max(array));
    printf("Mean: %.2f\n", mean(array));
    printf("Std: %.2f\n", std_sapma(array));
    
    printf("———————————————————————————————————————————————————————————————————————\n");
    printf("****************************** HISTOGRAM ******************************\n");
    printf("———————————————————————————————————————————————————————————————————————\n");

    float araliklar[AR + 1]; 
    for (int n = 0; n <= AR; ++n){
        float deger_araligi = (max(array) - min(array)) / AR;   
        araliklar[n] = min(array) + (n * deger_araligi);    

    }
    
    int counters[AR] = {}; 
    for (int p = 0; p < A; ++p){
        for (int a = 0; a < AR; ++a){  
            if (array[p] > araliklar[a] && array[p] < araliklar[a+1]){  
                counters[a]++;
                break; 
            } if(array[p] == max(array)){    
                counters[AR-1]++;
                break;  
            } if (array[p] == araliklar[a]){   
                counters[a]++;
                break; 
            } if (array[p] != max(array) && array[p] == araliklar[a+1]){ 
                counters[a+1]++;   
                break;           
            }

        }
    }

    printf("ARALIKLAR:       DEGER SAYISI:\n");
    int toplam_olcum_sayisi = 0; 
    for (int b = 0; b < AR; ++b){
        printf("[%.2f]-[%.2f] %3d ", araliklar[b], araliklar[b+1], counters[b]);
        
        for (int y = 0; y < counters[b]; ++y){
            printf("*");
            toplam_olcum_sayisi++;
        }
        printf("\n");
    }
    
    printf("\n");
    
    int max_eleman = max_int(counters, AR);   
    int bosluk_sayisi[AR] = {};

    for (int y = 0; y < AR; ++y){
        bosluk_sayisi[y] = max_eleman - counters[y]; 
    }
    
    for (int m = 0; m < max_eleman; ++m){ 
        printf("%2d", max_eleman - m); 
        for (int n = 0; n < AR; ++n){  
            if (bosluk_sayisi[n] > 0){  
                printf("——————————————");
                --bosluk_sayisi[n]; 
            }else if (bosluk_sayisi[n] == 0){
                printf("————— XXX ————");
            }
        }
        printf("\n"); 
    }

    printf("   "); 
    for (int a = 0; a < AR; ++a){
        printf("[%.2f-%.2f] ", araliklar[a], araliklar[a+1]); 
    }

    printf("\n\nTOPLAM OLCUM SAYISI: %d\n\n", toplam_olcum_sayisi);
   
	return 0;
}

/*
 * Parametre olarak verilen dizinin
 * en kucuk elemanini geri dondurur.
 */ 
float min(float array[]){ 
    float min_value = array[0];
    for (int k = 1; k < A; ++k){
        if (array[k] < min_value){
            min_value = array[k];
        }
    }
    return min_value;
}

/*
 * Parametre olarak verilen dizinin
 * en buyuk elemanini geri dondurur.
 */ 
float max(float array[]){
    float max_value = array[0];
    for (int k = 1; k < A; ++k){
        if (array[k] > max_value){
            max_value = array[k];
        }
    }
    return max_value;
}

/*
 * Parametre olarak verilen dizinin
 * elemanlarinin ortalamasini geri dondurur.
 */ 
float mean(float array[]){
    float mean_value, somme = 0;
    for (int m = 0; m < A; ++m){
        somme += array[m];
    }
    mean_value = somme / A;
    return mean_value;
}

/*
 * Parametre olarak verilen dizinin
 * standart sapmasini geri dondurur.
 */ 
float std_sapma(float array[]){
    float fark_kare_toplam = 0;
    for (int f = 0; f < A; ++f){
        float farklar = 0;   
        farklar = array[f] - mean(array);  
        fark_kare_toplam += pow(farklar, 2); 
    }
    float sonuc = sqrt(fark_kare_toplam / (A-1));
    return sonuc;
}

/*
 * Parametre olarak verilen dizinin
 * istenen aralik icerisindeki elemanlarindan
 * en buyuk elemani geri dondurur.
 */ 
int max_int(int array[], size_t size){
    int max_value = array[0];
    for (int k = 1; k < size; ++k){
        if (array[k] > max_value){
            max_value = array[k];
        }
    }
    return max_value;
}