#include "tp02.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int personCounter(int mode) {
    static int counter = 0;
    if(mode == 1) counter++;
    else if(mode == 2) counter--;
    return counter;
}


void afficherEle(Personne *person) {
    printf("\n= PERSONNE: %s %s INFO: %s VILLE: %s\n= NUMFIXE: %ld MOB: %ld CODEVILLE: %d\n", person->prenom, person->nom, person->info, person->ville, person->numeroFixe, person->numeroMobile, person->codeVille);
}

Personne *initEle(char *prenom, char *nom, char *info, char *ville, long int numeroFixe, long int numeroMobile, int codeVille) {
    Personne *new = calloc(1, sizeof(Personne));
    new->next = NULL;
    new->prev = NULL;
    new->prenom = calloc(strlen(prenom), sizeof(char));
    strcpy(new->prenom, prenom);
    new->nom = calloc(strlen(nom), sizeof(char));
    strcpy(new->nom, nom);
    new->info = calloc(strlen(info), sizeof(char));
    strcpy(new->info, info);
    new->ville = calloc(strlen(ville), sizeof(char));
    strcpy(new->ville, ville);
    new->numeroFixe = numeroFixe;
    new->numeroMobile = numeroMobile;
    new->codeVille = codeVille;
    personCounter(1);
    return new;
}

void delList(Personne **list, int mode) {
    if(!(*list)) return;
    Personne *tmp = *list, *cur;
    if(mode == 1)
        while(tmp != NULL) {
            cur = tmp;
            tmp = tmp->next;
            free(cur);
        }
    else if(mode == 2)
        do {
            cur = tmp;
            tmp = tmp->next;
            free(cur);
        } while(tmp != *list);
    *list = NULL;
}