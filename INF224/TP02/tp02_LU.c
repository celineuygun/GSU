#include "tp02.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ajouterLU(Personne **list, Personne *new) {
    Personne *tmp = *list;
    if(!(*list)) {
        *list = new;
    } else if(strcmp((*list)->prenom, new->prenom) >= 0) {
        new->next = *list;
        *list = new;
    } else {
        for(; tmp->next != NULL && strcmp(tmp->next->prenom, new->prenom) < 0; tmp = tmp->next);
        new->next = tmp->next;
        tmp->next = new;
    }
}

Personne **trouverPersonnesLU(Personne *list, char *search) {
    Personne *tmp = list;
    int numPerson = personCounter(0);
    Personne **personsFound = calloc(numPerson + 1, sizeof(Personne*));
    int counter = 0, i = 0;
    for(; tmp != NULL && i < numPerson; tmp = tmp->next) {
        if(!strcmp(tmp->prenom, search)) {
            personsFound[i] = tmp;
            counter++;
            i++;
        } else {
            if(counter) break;
        }
    }
    i++;
    personsFound[i] = 0; 
    return personsFound;
}

void supprimerEleLU(Personne **list, char *prenom) {
    if(!(*list)) {
        printf("La liste est deja vide.");
        return;
    }
    int numPerson = personCounter(0);
    Personne **personsFound = trouverPersonnesLU(*list, prenom);
    if(personsFound[0] == 0) {
        printf("\n%s n'est pas sur la liste.\n", prenom);
        return;
    }
    Personne *retVal = personsFound[0], *tmp = NULL;
    if(numPerson > 1 && personsFound[1] != 0) {
        printf("\nIl y a plus d'une personne qui s'appelle %s.\n", prenom);
        for(int i = 0; personsFound[i] != 0; ++i) {
            afficherEle(personsFound[i]);
        } printf("\nEntez son nom pour le supprimer: ");
        char nom[20];
        scanf("%s", nom);
        for(int i = 0; personsFound[i] != 0; ++i) {
            if(!strcmp(personsFound[i]->nom, nom)) {
                retVal = personsFound[i];
            }
        } if(!retVal) {
            printf("\n%s %s n'est pas sur la liste.\n", prenom, nom);
            return;
        }
    }
    for(tmp = *list; tmp != NULL; tmp = tmp->next) {
        if(retVal == *list) {
            *list = retVal->next;
        }
        if(tmp->next == retVal) {
            tmp->next = retVal->next;
        }
    } printf("\n%s %s a ete supprime.\n", retVal->prenom, retVal->nom);
    free(retVal);
    free(personsFound);
    personCounter(2);
}