#include "tp03.h"
#include <stdio.h>
// STACK
/*
 * head = array basi indexi(yeni eleman bir eksigi indexine eklenecek)
 * tail = arrayin son elemaninin indexi
 */

void empilerTab(Tab *tab, int data) {
    if(!isFull(tab)) {
        if(tab->head == 0) {
            tab->head = tab->capacity - 1;
            if(tab->tail == -1) tab->tail = tab->head;
        }
        else tab->head--;
        tab->tableau[tab->head] = data;
        printf("\n%d a ete ajoute.\n", data);
    } else {
        printf("\nFile est deja complete.\n");
    }
}

int depilerTab(Tab *tab) {
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
