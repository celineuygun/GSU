#include <stdio.h>
#include <stdlib.h>
#include "fonc.h"

Liste *create_liste(int n) {
    Liste *l = calloc(1, sizeof(Liste));
    if(l) {
        l->arr = calloc(n, sizeof(int));
        l->size = n;
    } return l;
}

void afficher_liste(Liste *l) {
    printf("\n");
    for(int i = 0; i < l->size; ++i)
        printf("%d ", l->arr[i]);
    printf("\n");
}

int genere_nombre_lehmer(int u_i) {
    const int a = 137, c = 187, m = 256;
    return (a * u_i + c) % m;
}

int genere_liste_lehmer(Liste *l, int u_0) {
    if(!l) return 0;
    l->arr[0] = genere_nombre_lehmer(u_0);
    for(int i = 1; i < l->size; ++i) {
        l->arr[i] = genere_nombre_lehmer(l->arr[i-1]);
    } return 1;
}

float calcule_moyennne(Liste *l) {
    float sum = 0;
    for(int i = 0; i < l->size; ++i)
        sum += l->arr[i];
    return sum / l->size;
}

void calcule_minmax(Liste *l, int i, int *min, int *max) {
    if(i == -1)
        return;
    if(l->arr[i] <= *min) {
        if(l->arr[i] >= *max)
            *max = l->arr[i];
        *min = l->arr[i];
    } else
        if(l->arr[i] >= *max)
            *max = l->arr[i];
    return calcule_minmax(l, i - 1, min, max);
}

void calcule_repartition(Liste *l, Liste *tab) {
    for(int i = 0; i < tab->size; ++i)
        tab->arr[i] = 0;
    for(int i = 0; i < l->size; ++i)
        tab->arr[l->arr[i]]++;
}

void affiche_histogramme (Liste *tab) {
    for(int i = 0; i < tab->size; ++i) {
        printf("%3d\t", i);
        for(int j = 0; j < tab->arr[i]; ++j) {
            printf("* ");
        } printf("\n");
    }
}