#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arr.h"
#include "ensemble_ll.h"
#include "ensemble_tab.h"

int main() {
    ArrDy *array = NULL;
    SetPtr **sets = NULL;
    int *smallest = NULL;
    int response = 0, mode = 0, capacity = 0, nombre = 0, nombre2 = 0, index = 0, elemNum = 0;
    bool stop = false;

    printf("Choissisez un type de structure.\n");
    printf("[1] Le tableau dynamique\n[2] L'ensemble disjoint (liste chainee)\n[3] L'ensemble disjoint (tableau)\n>> ");
    scanf(" %d", &mode);
    while(!(mode >= 1 && mode <= 3)) {
        printf("\nMerci de faire un choix valable.\n>> ");
        scanf(" %d", &mode);
    }

    if(mode == 1) {
        printf("\nEntrez la capacite initale du tableau.\n>> ");
        scanf(" %d", &capacity);
        array = createArrDy(capacity);
    } else {
        printf("\nEntrez un nombre pour construire un nouvel ensemble contenant le nombre donné d'ensembles de singletons.\n>> ");
        scanf(" %d", &elemNum);
        if(mode == 2) {
            sets = calloc(elemNum, sizeof(SetPtr *));
            for(int i = 0; i < elemNum; ++i)
                sets[i] = makeSetLl(i);
        } else
            smallest = calloc(elemNum, sizeof(int));
            for(int i = 0; i < elemNum; ++i)
                makeSetTab(smallest, i);
    }

    while(stop != true) {
        if(mode == 1) {
            printf("\nAppuyez sur 1 pour ajouter un element a la fin\n");
            printf("Appuyez sur 2 pour supprimer un element\n");
            printf("Appuyez sur 3 pour l'element a n'importe quel indice\n");
            printf("Appuyez sur 4 pour changer la valeur d'un element\n");
            printf("Appuyez sur 5 pour afficher la taille et la capacite du tableau dynamique\n");
            printf("Appuyez sur 6 pour afficher le tableau dynamique\n");
            printf("Appuyez sur 7 pour quitter le menu\n>> ");
        } else {
            printf("\nAppuyez sur 1 pour fusionne les ensembles auxquels appartiennent les deux elements donnes\n");
            printf("Appuyez sur 2 pour tester si les deux elements donnes sont membres du meme ensemble\n");
            printf("Appuyez sur 3 pour renvoie le nombre total d'ensembles disjoints\n");
            printf("Appuyez sur 4 pour renvoie la taille de l'ensemble dont l'élément donné est membre\n");
            printf("Appuyez sur 5 pour afficher l'ensemble dont l'élément donné est membre\n");
            printf("Appuyez sur 6 pour afficher tous l'ensembles disjoints'\n");
            printf("Appuyez sur 7 pour quitter le menu\n>> ");
        } scanf(" %d", &response);

        switch(response) {
            case 1: 
                if(mode == 1) {
                    printf("\nEntrez un nombre que vous souhaitez ajouter: ");
                    scanf(" %d", &nombre);
                    pushBack(&array, nombre);
                    printf("\n%d est ajoute\n", nombre);
                } else {
                    printf("\nEntrez deux nombres entre [0, %d]: ", elemNum - 1);
                    scanf(" %d %d", &nombre, &nombre2);
                    if(mode == 2) mergeSetsLl(sets, nombre, nombre2);
                    else unionTab(smallest, elemNum, nombre, nombre2);
                    printf("\nLes ensembles sont fusionnes\n");
                } break;
            
            case 2:
                if(mode == 1) {
                    printf("\nEntrez l'indice de l'element que vous souhaitez supprimer: ");
                    scanf(" %d", &index);
                    removeItem(array, index);
                } else {
                    printf("\nEntrez deux nombres entre [0, %d]: ", elemNum - 1);
                    scanf(" %d %d", &nombre, &nombre2);
                    int retVal = 0;
                    if(mode == 2) retVal = areInSameSetLl(sets, nombre, nombre2);
                    else retVal = areInSameSetTab(smallest, nombre, nombre2);
                    printf("\n%d et %d %s membres du meme ensemble\n", nombre, nombre2, retVal ? "sont" : "ne sont pas");
                } break;

            case 3:
                if(mode == 1){
                    printf("\nEntrez l'indice de l'element que vous souhaitez afficher: ");
                    scanf(" %d", &index);
                    nombre = get(array, index);
                    if(nombre != -1) printf("\nL'element a l'indice %d: %d\n", index, nombre);
                } else {
                    int retVal = 0;
                    if(mode == 2) retVal = disjointSetCounterLl(0);
                    else retVal = disjointSetCounterTab(0);
                    printf("\nLe nombre total d'ensembles disjoints: %d\n", retVal);
                } break;

            case 4:
                if(mode == 1) {
                    printf("\nEntrez l'indice de l'element dont vous souhaitez changer la valeur: ");
                    scanf(" %d", &index);
                    printf("\nEntrez une nouvelle valeur: ");
                    scanf(" %d", &nombre);
                    set(array, index, nombre);
                } else {
                    printf("\nEntrez un nombre entre [0, %d]: ", elemNum - 1);
                    scanf(" %d", &nombre);
                    int retVal = 0;
                    if(mode == 2) retVal = getSizeOfSetLl(sets[nombre]);
                    else retVal = getSizeOfSetTab(smallest, elemNum, nombre);
                    printf("\nLa taille de l'ensemble dont l'élément donné est membre: %d\n", retVal);
                } break;

            case 5:
                if(mode == 1) printf("\n\tcapacite: %-3d taille: %-3d\n", getCapacity(array), getSize(array));
                else {
                    printf("\nEntrez un nombre entre [0, %d]: ", elemNum - 1);
                    scanf(" %d", &nombre);
                    if(mode == 2) {
                        printf("\n");
                        displaySetLl(sets[nombre]);
                        printf("\n");
                    } else {
                        displaySetTab(smallest, elemNum, nombre);
                    }
                } break;
            
            case 6:
                if(mode == 1) printArrDy(array);
                else {
                    if(mode == 2) displaySetsLl(sets, elemNum);
                    else displaySmallest(smallest, elemNum);
                } break;

            case 7:
                stop = true;
                if(mode == 1) deleteArrDy(&array);
                else if(mode == 2) deleteSetsLl(&sets, elemNum);
                else free(smallest);
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}