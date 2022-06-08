#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Ll *push(Ll *list, Arb *node) {
    Ll *new = calloc(1, sizeof(Ll)), *tmp;
    new->node = node;
    new->next = NULL;
    if(!list) {
        return new;
    }
    for(tmp = list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return list;
}

Arb *pop(Ll **list) {
    if(!(*list)) {
        return NULL;
    } Arb *retVal = (*list)->node;
    Ll *tmp = *list;
    (*list) = (*list)->next;
    free(tmp);
    return retVal;
}
