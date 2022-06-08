#include "Complexe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10

double partieReel(complexe z) {
    return z.re;
}

double partieImag(complexe z) {
    return z.im;
}

void afficheComplexe(complexe *z) {
    printf("z = %.2f + %.2fi", z->re, z->im);
}

double moduleComplexe(complexe *z) {
    double sq = sqrt(pow(z->re, 2) + pow(z->im, 2));
    return (sq >= 0 ? sq : -sq);
}

complexe saisitComplexe() {
    complexe z;
    printf("Entrez la partie reelle: ");
    scanf(" %lf", &z.re);
    printf("Entrez la partie imaginaire: ");
    scanf(" %lf", &z.im);
    return z;
}

complexe multiComplexe(complexe a, complexe b) {
    complexe z;
    z.re = (a.re * b.re) - (a.im * b.im);
    z.im = (a.re * b.im) + (a.im * b.re);
    return z;
}

void remplitTableau(complexe *tab) {
    srand((unsigned int)time(NULL));
    for(int i=0; i<N; ++i){
        tab[i].im = ((float)rand()/(float)(RAND_MAX)) * 1.0;
        tab[i].re = ((float)rand()/(float)(RAND_MAX)) * 1.0;
        printf("tab[%d]  ", i);
        afficheComplexe(&tab[i]);
        printf("  |z| = %.2f\n", moduleComplexe(&tab[i]));
    }
}