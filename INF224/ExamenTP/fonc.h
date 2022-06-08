#ifndef FONC_H_
#define FONC_H_

typedef struct liste {
    int *arr;
    int size;
} Liste;

Liste *create_liste(int n);
void afficher_liste(Liste *l);
int genere_nombre_lehmer(int u_i);
int genere_liste_lehmer(Liste *L, int u_0);
float calcule_moyennne(Liste *l);
void calcule_minmax(Liste *l, int i, int *min, int *max);
void calcule_repartition(Liste *l, Liste *tab);
void affiche_histogramme(Liste *tab);

#endif