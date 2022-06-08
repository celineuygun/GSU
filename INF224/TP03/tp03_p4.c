#include "tp03.h"
#include <stdio.h>
#include <stdlib.h>
// QUEUE

Ll *enfilerLl(Ll *list, int data) {
    Ll *new = calloc(1, sizeof(Ll)), *tmp;
    new->data = data;
    new->next = NULL;
    printf("\n%d a ete ajoute.\n", data);
    if(!list) {
        return new;
    }
    for(tmp = list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return list;
}

int defilerLl(Ll **list) {
    if(!(*list)) {
        printf("\nFile est deja vide.\n");
        return -1;
    } int retVal = (*list)->data;
    Ll *tmp = *list;
    (*list) = (*list)->next;
    free(tmp);
    return retVal;
}
