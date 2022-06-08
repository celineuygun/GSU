#include <stdio.h>
#include "Complexe.h"
#define N 10

int main() {
    int indice;
    double module, largest;
    complexe p, s, m, tab[N];

    printf("\nENTREZ LE 1ER NOMBRE COMPLEXE\n");
    p = saisitComplexe();
    afficheComplexe(&p);
    
    printf("\n\nENTREZ LE 2EME NOMBRE COMPLEXE\n");
    s = saisitComplexe();
    afficheComplexe(&s);
    
    printf("\n\nMULTIPLICATION DE 2 COMPLEXES\n");
    m = multiComplexe(p, s);
    afficheComplexe(&m);
    module = moduleComplexe(&m);
    printf("\n|z| = %.2f\n", module);
    
    printf("\n-------- TABLEAU DES STRUCTURES --------\n");
    remplitTableau(tab);

    printf("\nLE NOMBRE COMPLEXE AVEC LE MAX MODULE:\n");
    largest = moduleComplexe(&tab[0]);
    for(int i = 0; i<N; ++i){
        if(largest < moduleComplexe(&tab[i])){largest = moduleComplexe(&tab[i]); indice = i;}
    }
    afficheComplexe(&tab[indice]);
    printf("\n|z| = %.2f ", largest);
    printf("\nindice: %d\n", indice);
    return 0;
}