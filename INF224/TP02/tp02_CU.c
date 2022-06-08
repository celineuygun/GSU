#include "tp02.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ajouterCU(Personne **list, Personne *new) {
    Personne *tmp = *list;
    if(!(*list)) {
        new->next = new;
        *list = new;
    } else if(strcmp((*list)->prenom, new->prenom) >= 0) {
        for(; tmp->next != *list; tmp = tmp->next);
        tmp->next = new;
        new->next = *list;
        *list = new;
    } else {
        for(tmp = *list; tmp->next != *list && strcmp(tmp->next->prenom, new->prenom) < 0; tmp = tmp->next);
        new->next = tmp->next;
        tmp->next = new;
    }
}

Personne **trouverPersonnesCU(Personne *list, char *search) {
    Personne *tmp = list;
    int numPerson = personCounter(0);
    Personne **personsFound = calloc(numPerson + 1, sizeof(Personne*));
    int counter = 0, i = 0;
    do {
        if(!strcmp(tmp->prenom, search)) {
            personsFound[i] = tmp;
            counter++;
            i++;
        } else {
            if(counter) break;
        } tmp = tmp->next;
    } while(tmp != list && i < numPerson);
    i++;
    personsFound[i] = 0; 
    return personsFound;
}

void supprimerEleCU(Personne **list, char *prenom) {
    if(!(*list)) {
        printf("La liste est deja vide.");
        return;
    }
    int numPerson = personCounter(0);
    Personne **personsFound = trouverPersonnesCU(*list, prenom);
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
    } tmp = *list;
    do {
        if(retVal == *list) {
            if(retVal->next != *list) {
                Personne *cur = *list;
                for(; cur->next != *list; cur = cur->next);
                cur->next =  (*list)->next;
                *list = retVal->next;
            } else if(retVal->next == *list) {
                *list = NULL;
            } break;
        } else if(tmp->next == retVal) {
            tmp->next = retVal->next;
            break;
        } tmp = tmp->next;
    } while(tmp != *list);
    printf("\n%s %s a ete supprime.\n", retVal->prenom, retVal->nom);
    if(retVal) free(retVal);
    free(personsFound);
    personCounter(2);
}