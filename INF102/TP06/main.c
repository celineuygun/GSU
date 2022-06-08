#include <stdio.h>

float* minAdr(float[], size_t);

int main() {
    size_t size = 1;    
    printf("Entrez la taille souhaitee pour le tableau: ");
    scanf(" %zd", &size);
    printf("—————————————————————————————————————————\n");
    float a[size];
    for(int i = 0; i < size; ++i){
        printf("Entrez n˚%d d'element du tableau: ", i+1);
        scanf(" %f", &a[i]);
    }
    printf("—————————————————————————————————————————\n");
    printf("INDICE     NOMBRE        ADRESSE\n");
    size_t m = size;
    while(m != 0){
        printf("%3lu       %-8g    %p    \n" , size - m, a[size - m], &a[size - m]);
        --m;
    }
    printf("—————————————————————————————————————————\n");
    
    
    float *adrdupluspetit;
    adrdupluspetit = minAdr(a, size);
    printf("Le plus petit nombre dans le tableau: %g\n", *adrdupluspetit);
    printf("L’adresse du plus petit nombre: %p\n", adrdupluspetit);
    printf("L’indice du plus petit nombre: %ld\n", (adrdupluspetit - a));

    
    return 0;
}

float* minAdr(float x[], size_t size){
    float *adressepluspetit = x;
    for (int f = 1; f < size; ++f){
        if(x[f] < *adressepluspetit){
            adressepluspetit = &x[f];
        }
    }
    return adressepluspetit;
}