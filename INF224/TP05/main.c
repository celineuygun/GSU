#include <stdio.h>
#include <stdbool.h>
#include "file.h"
#include "tas.h"

int main() {
    Noeud *pQueue = NULL, *tmp = NULL;
    Tas *heap = NULL;
    int response = 0, mode = 0, capacity = 0, item = 0, prio = 0;
    bool stop = false;

    printf("Choissisez un type de structure.\n");
    printf("[1] La file d'attente prioritaire\n[2] Le tas binaire\n>> ");
    scanf(" %d", &mode);
    while(!(mode == 1 || mode == 2)) {
        printf("\nMerci de faire un choix valable. Entrez seulement [1] ou [2].\n>> ");
        scanf(" %d", &mode);
    }

    if(mode == 2) {
        printf("\nEntrez la capacite du tableau qui sera utilise pour le tas: ");
        scanf(" %d", &capacity);
        heap = createMaxHeap(capacity);
    }

    while(stop != true) {
        printf("\nAppuyez sur 1 pour ajouter un element\n");
        printf("Appuyez sur 2 pour supprimer un element selectionne\n");
        printf("Appuyez sur 3 pour supprimer un element avec la priorite la plus elevee\n");
        printf("Appuyez sur 4 pour l'element avec la priorite la plus elevee\n");
        printf("Appuyez sur 5 pour changer la priorite d'un element\n");
        if(mode == 1) printf("Appuyez sur 6 pour afficher la file d'attente prioritaire\n");
        else printf("Appuyez sur 6 pour afficher le tas binaire\n");
        printf("Appuyez sur 7 pour quitter le menu\n>> ");
        scanf(" %d", &response);

        switch(response) {
            case 1: 
                if(mode == 1) {
                    printf("\nEntrez un nombre et sa priorite que vous souhaitez ajouter.\nNombre: ");
                    scanf(" %d", &item);
                    printf("Priorite: ");
                    scanf(" %d", &prio);
                    insertEleFile(&pQueue, item, prio);
                    printf("\n%d est ajoute\n", item);
                } else {
                    printf("\nEntrez un priorite de l'element que vous souhaitez ajouter: ");
                    scanf(" %d", &prio);
                    insertEleHeap(&heap, prio);
                } break;
            
            case 2:
                if(mode == 1) printf("\nEntrez un nombre que vous souhaitez supprimer: ");
                else printf("\nEntrez l'indice de l'element que vous souhaitez supprimer: ");
                scanf(" %d", &item);
                if(mode == 1) removeEleFile(&pQueue, item);
                else removeEleHeap(heap, item);
                break;

            case 3:
                if(mode == 1) extractMaxFile(&pQueue);
                else {
                    prio = extractMaxHeap(heap);
                    printf("\n%d a supprime.\n", prio);
                } break;

            case 4:
                if(mode == 1) {
                    tmp = getMaxFile(pQueue);
                    printf("\nL'element avec la priorite la plus elevee:\n%2d: [priority %2d]\n", tmp->item, tmp->priority);
                } else {
                    prio = getMaxHeap(heap);
                    printf("\nLa priorite la plus elevee: %2d\n", prio);
                } break;

            case 5:
                if(mode == 1) printf("\nEntrez un element dont vous souhaitez changer la priorite: ");
                else printf("\nEntrez l'indice dont vous souhaitez changer la priorite: ");
                scanf(" %d", &item);
                printf("Entrez la nouvelle priorite: ");
                scanf(" %d", &prio);
                if(mode == 1) changePriorityFile(&pQueue, item, prio);
                else changePriorityHeap(heap, item, prio);
                break;
            
            case 6:
                if(mode == 1) displayFile(pQueue);
                else displayHeap(*heap);
                break;

            case 7:
                stop = true;
                deleteHeap(&heap);
                deleteFile(&pQueue);
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}