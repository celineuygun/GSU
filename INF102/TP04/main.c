#include <stdio.h>

int rakamlarToplami(int);

int main(){
    int x, result;
    printf("Bir sayi giriniz: ");
    scanf("%d", &x);
    result = rakamlarToplami(x);
    printf("%d sayisinin rakamlari toplami: %d\n", x, result);
    return 0;
}

int rakamlarToplami(int sayi){
    int basamak = 1, k = 1, deger_toplam = 0; 
    while(1){
        if (sayi / (10*k) != 0)++basamak;
        else break;
        k *= 10;
    }
    while(basamak > 0){
        int deger = sayi / k;
        deger_toplam += deger;
        sayi -= deger * k;
        if(basamak == 0) break;
        basamak--;
        k = k/10;
    }
    return deger_toplam;
}