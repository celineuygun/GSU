#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "fonc.h"

// #define BORNE_MAX 256   

int main() {
    int n = 1000;
    Liste *l = create_liste(n);
    
    srand(time(NULL));
    int u_0 = rand() % 1000;
    printf("\nRandom generated u_0: %3d\n", u_0);
    genere_liste_lehmer(l, u_0);
    printf("\n=============== Liste\n");
    afficher_liste(l);

    printf("\nMoyenne: %.2f\n",calcule_moyennne(l));
    int min = INT_MAX, max = INT_MIN;
    calcule_minmax(l, n-1, &min, &max);
    printf("\nMin: %3d Max %3d\n", min, max);

    // Liste *tab = create_liste(BORNE_MAX);
    Liste *tab = create_liste(max + 1);
    calcule_repartition(l, tab);
    printf("\n=============== Tab\n");
    afficher_liste(tab);
    printf("\n");
    affiche_histogramme(tab);

    return 0;
}
