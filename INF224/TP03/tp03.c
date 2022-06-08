#include "tp03.h"
#include <stdio.h>
#include <stdlib.h>

Tab *initTab(unsigned capacity) {
    Tab *new = calloc(1, sizeof(Tab));
    if(new) {
        new->tableau = calloc(capacity, sizeof(int));
        if(!new->tableau) exit(1);
        new->capacity = capacity;
        new->head = 0;
        new->tail = -1;
    } return new;
}

int isFull(Tab *tab) {
    if(tab->tail == -1) return 0;
    else if(tab->tail + 1 == tab->capacity) return(0 == tab->head);
    else return(tab->tail + 1 == tab->head);
}

int isEmpty(Tab *tab) {
    return (!tab || tab->tail == -1);
}

void deleteTab(Tab **tab) {
    if(!(*tab)) return;
    free((*tab)->tableau);
    (*tab)->tableau = NULL;
    free(*tab);
    *tab = NULL;
}

void printTab(Tab *tab) {
    if(isEmpty(tab)) {
        printf("\nFile est vide.\n");
        return;
    }
    printf("\n");
    int i = tab->head;
    while(i != tab->tail) {
        printf("%d -> ", tab->tableau[i]);
        if(i + 1 == tab->capacity) i = 0;
        else i++;
    } printf("%d -> ", tab->tableau[i]);
    printf("NULL\n");
}

void deleteLl(Ll **list) {
    Ll *tmp = *list, *cur;
    while(tmp != NULL) {
        cur = tmp;
        tmp = tmp->next;
        free(cur);
    } *list = NULL;
}

void printLl(Ll *list) {
    if(!list) {
        printf("\nFile est vide.\n");
        return;
    }
    printf("\n");
    for(Ll *tmp = list; tmp != NULL; tmp = tmp->next)
        printf("%d -> ", tmp->data);
    printf("NULL\n");
}
