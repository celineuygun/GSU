#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp03.h"

int main() {
    Tab *tab = NULL;
    Ll *list = NULL;
    int capacity = 0, response = 0, data = 0, mode;
    bool stop = false;

    printf("Choissisez un type de structure.\n");
    printf("[1] pile avec un tableau\n[2] pile avec une liste chainee\n[3] file avec un tableau\n[4] file avec une liste chainee\n>> ");
    scanf(" %d", &mode);
    while(mode < 1 || mode > 4) {
        printf("\nMerci de faire un choix valable.\n>> ");
        scanf(" %d", &mode);
    }

    if(mode == 1 || mode == 3 ) {
        printf("\nEntrez la taille de la tableau que vous souhaitez creer: ");
        scanf(" %d", &capacity);
        tab = initTab(capacity);
    }

    while(stop != true) {
        if(mode == 1 || mode == 2) {
            printf("\nAppuyez sur 1 pour empiler\n");
            printf("Appuyez sur 2 pour depiler\n");
            printf("Appuyez sur 3 pour afficher la pile\n");
        } else if(mode == 3 || mode == 4) {
            printf("\nAppuyez sur 1 pour enfiler\n");
            printf("Appuyez sur 2 pour defiler\n");
            printf("Appuyez sur 3 pour afficher la file\n");
        } printf("Appuyez sur 4 pour quitter le menu\n>> ");
        scanf(" %d", &response);

        switch (response) {
            case 1:
                printf("\nEntrez la nombre entier que vous souhaitez ajouter: ");
                scanf(" %d", &data);
                if(mode == 1) empilerTab(tab, data);
                else if(mode == 3) enfilerTab(tab, data);
                else if(mode == 2) list = empilerLl(list, data);
                else list = enfilerLl(list, data);
                break;

            case 2:
                if(mode == 1) data = depilerTab(tab);
                else if(mode == 3) data = defilerTab(tab);
                else if(mode == 2) data = depilerLl(&list);
                else data = defilerLl(&list);
                if(data != -1) printf("\n%d a ete supprime.\n", data);
                break;
            
            case 3:
                if(mode == 1 || mode == 3) printTab(tab);
                else if(mode == 2 || mode == 4) printLl(list);
                break;

            case 4:
                deleteTab(&tab);
                deleteLl(&list);
                stop = true;
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}