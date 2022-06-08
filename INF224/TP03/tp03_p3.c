#include "tp03.h"
#include <stdio.h>
// QUEUE
/*
 * head = array basi(dequeue ile elde edilecek olan elemanin) indexi
 * tail = arrayin son elemaninin indexi (bir sonraki indexe yeni eleman eklenir)
 */

void enfilerTab(Tab *tab, int data) {
    if(!isFull(tab)) {
        if(tab->tail + 1 == tab->capacity) {
            tab->tail = 0;
        } else {
            tab->tail++;
        } tab->tableau[tab->tail] = data;
        printf("\n%d a ete ajoute.\n", data);
    } else {
        printf("\nFile est deja complete.\n");
    }
}

int defilerTab(Tab *tab) {
    if(isEmpty(tab)) {
        printf("\nFile est deja vide.\n");
        return -1;
    }
    int retVal = tab->tableau[tab->head];
    if(tab->head == tab->tail) {
        tab->head = 0;
        tab->tail = -1;
    } else if(tab->head + 1 == tab->capacity) tab->head = 0;
    else tab->head++;
    return retVal;
}
