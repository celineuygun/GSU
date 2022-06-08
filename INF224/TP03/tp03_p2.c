#include "tp03.h"
#include <stdio.h>
#include <stdlib.h>
// STACK

Ll *empilerLl(Ll *list, int data) {
    Ll *new = calloc(1, sizeof(Ll));
    new->data = data;
    new->next = list;
    list = new;
    printf("\n%d a ete ajoute.\n", data);
    return list;
}

int depilerLl(Ll **list) {
    if(!(*list)) {
        printf("\nFile est deja vide.\n");
        return -1;
    } int retVal = (*list)->data;
    Ll *tmp = *list;
    (*list) = (*list)->next;
    free(tmp);
    return retVal;
}
