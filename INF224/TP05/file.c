#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void deleteFile(Noeud **queue) {
    if(!(*queue)) return;
    Noeud *tmp = *queue;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        free(tmp->prev);
    } free(tmp);
    *queue = NULL;
}

// Deplacement de tmp vers la gauche par priorite sur liste chainee
void shiftLeft(Noeud **queue, Noeud *tmp) {
    Noeud *prev = tmp->prev;
    if(prev && prev->priority < tmp->priority) {
        if(tmp->next) tmp->next->prev = prev;
        tmp->prev = prev->prev;
        if(prev->prev) prev->prev->next = tmp;
        else *queue = tmp;
        prev->prev = tmp;
        prev->next = tmp->next;
        tmp->next = prev;
        shiftLeft(queue, tmp);
    }
}

// Deplacement de tmp vers la droite par priorite sur liste chainee
void shiftRight(Noeud **queue, Noeud *tmp) {
    Noeud *next = tmp->next;
    if(next && next->priority >= tmp->priority) {
        if(next->next) next->next->prev = tmp;
        tmp->next = next->next;
        if(tmp->prev) tmp->prev->next = next;
        else *queue = next;
        next->next = tmp;
        next->prev = tmp->prev;
        tmp->prev = next;
        shiftRight(queue, tmp);
    }
}

void insertEleFile(Noeud **queue, int item, int priority) {
    Noeud *new = calloc(1, sizeof(Noeud));
    if(!new) exit(1);
    new->item = item;
    new->priority = priority;
    new->next =NULL;
    new->prev = NULL;
    if(!(*queue))
        *queue = new;
    else {
        (*queue)->prev = new; // to place new node at the head of the queue first
        new->next = *queue;
        *queue = new;
        shiftRight(queue, new); // to move new node where it needs to be
    }
}

Noeud *getMaxFile(Noeud *queue) {
    return queue;
}

void extractMaxFile(Noeud **queue) {
    Noeud *tmp = getMaxFile(*queue);
    (*queue)->next->prev = NULL;
    (*queue) = (*queue)->next;
    printf("\nLe noeud %d est supprime.\n", tmp->item);
    free(tmp);
}

void removeEleFile(Noeud **queue, int item) {
    if(*queue) {
        Noeud *tmp = *queue;
        if(item == (*queue)->item) {
            extractMaxFile(queue);
            return;
        } for(; tmp && tmp->item != item; tmp = tmp->next);
        if(!tmp) {
            printf("\nIl n'y a pas de %d.\n", item);
            return;
        } tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        printf("\nLe noeud %d est supprime.\n", tmp->item);
        free(tmp);
    } else printf("\nLa file est deja vide.\n");
}

void changePriorityFile(Noeud **queue, int item, int priority) {
    if(*queue) {
        Noeud *tmp = *queue;
        for(; tmp && tmp->item != item; tmp = tmp->next);
        if(!tmp) {
            printf("\nIl n'y a pas de %d. Donc %d est ajoute comme un nouvel element.\n", item, item);
            insertEleFile(queue, item, priority);
            return;
        } tmp->priority = priority;
        // To place tmp in the right place
        shiftLeft(queue, tmp);
        shiftRight(queue, tmp);
    } else printf("\nCreez d'abord une file d'attente prioritaire.\n");
}

void displayFile(Noeud *queue) {
    printf("\n");
    if(queue) {
        for(Noeud *tmp = queue; tmp != NULL; tmp = tmp->next)
            printf("%2d: [priority %2d]\n", tmp->item, tmp->priority);
    } else printf("NULL\n");
}