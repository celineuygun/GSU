#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "tree.h"
#include "treeAVL.h"

int main() {
    Arb *root = NULL, *tmp = NULL, *T1 = NULL, *T2 = NULL;
    int response = 0, nombre = 0, mode = 0, min = INT_MAX, max = INT_MIN;
    int x = 0, y = 0;
    bool stop = false;

    printf("Choissisez un type d'arbre.\n");
    printf("[1] arbre binaire\n[2] arbre AVL\n>> ");
    scanf(" %d", &mode);
    while(!(mode == 1 || mode == 2)) {
        printf("\nMerci de faire un choix valable. Entrez seulement [1] ou [2].\n>> ");
        scanf(" %d", &mode);
    }
    
    while(stop != true) {
        printf("\nAppuyez sur 1 pour ajouter un nombre\n");
        printf("Appuyez sur 2 pour supprimer un nombre\n");
        printf("Appuyez sur 3 pour chercher un nombre\n");
        if(mode == 1) printf("Appuyez sur 4 pour chercher le plus petit ou grand nombre\n");
        else printf("Appuyez sur 4 pour la hauteur de l'arbre\n");
        printf("Appuyez sur 5 pour la taille de l'arbre\n");
        printf("Appuyez sur 6 pour le noeud suivant, le descendant gauche et l'ancestre droit\n");
        printf("Appuyez sur 7 pour la recherche de gamme\n");
        printf("Appuyez sur 8 pour fusionner l'arbre avec le nouveau\n");
        printf("Appuyez sur 9 pour diviser l'arbre en 2 arbres\n");
        printf("Appuyez sur 10 pour afficher l'arbre\n");
        printf("Appuyez sur 11 pour quitter le menu\n>> ");
        scanf(" %d", &response);

        switch (response) {
            case 1:
                printf("\nEntrez le nombre que vous souhaitez ajouter: ");
                scanf(" %d", &nombre);
                if(mode == 1) insertNode(&root, createNode(nombre));
                else insertAVL(&root, createNode(nombre));
                printf("\nLe noeud %d est ajoute.\n", nombre);
                break;

            case 2:
                printf("\nEntrez le nombre que vous souhaitez supprimer: ");
                scanf(" %d", &nombre);
                if(mode == 1) deleteNode(&root, nombre);
                else if(mode == 2) deleteNodeAVL(&root, nombre);
                printf("\nLe noeud %d est supprime.\n", nombre);
                break;

            case 3:
                printf("\nEntrez le nombre que vous souhaitez chercher: ");
                scanf(" %d", &nombre);
                tmp = search(root, nombre);
                if(tmp) printf("L'arbre contient le nombre %d.\n", nombre);
                else printf("Il n'y a pas de %d.\n", nombre);
                break;

            case 4:
                if(mode == 1) {
                    printf("\nVous souhaitez chercher le plus petit(1) ou grand nombre(2)?\n>> ");
                    scanf(" %d", &nombre);
                    if(!(nombre == 1 || nombre == 2)) {
                        printf("\nMerci de faire un choix valable. Appuyez 1 pour le plus petit et 2 pour grand nombre.");
                        while(!(nombre == 1 || nombre == 2)) {
                            printf("\n>> ");
                            scanf(" %d", &nombre);
                        }
                    } if(nombre == 1) min = findMin(root, min);
                    else if(nombre == 2) max = findMax(root, max);
                    if(min != INT_MAX) printf("\nLe plus petit nombre dans l'arbre est %d.\n", findMin(root, INT_MAX));
                    if(max != INT_MIN) printf("\nLe plus grand nombre dans l'arbre est %d.\n", findMax(root, INT_MIN));
                    else printf("\nL'arbre est vide.\n");
                } else printf("\nLa hauteur de l'arbre est %d\n", getHeight(root));
                break;

            case 5:
                printf("\nLa taille de l'arbre est %d\n", getSize(root));
                break;

            case 6:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &nombre);
                tmp = search(root, nombre);
                if(!tmp) {
                    printf("Il n'y a pas de %d.\n", nombre);
                    break;
                }
                printf("\nLe noeud suivant: %d\nLe descendant gauche: %d\nL'ancetre droit: %d\n", nextNode(tmp)->data, leftDescendant(tmp)->data, rightAncestor(tmp)->data);
                break;

            case 7:
                printf("\nEntrez deux nombres pour l'intervalle: ");
                scanf(" %d %d", &x, &y);
                int *list = rangeSearch(root, x, y);
                printf("\n[ ");
                for(int i = 0; list[i] != INT_MIN; ++i) {
                    printf("%d ", list[i]);
                } printf("]\n");
                free(list);
                break;
            
            case 8:
                printf("\nLe nouvel arbre a combien d'elements?\n>> ");
                scanf(" %d", &x);
                tmp = NULL;
                for(int i = 0; i < x; ++i) {
                    printf("Entrez le %deme nombre que vous souhaitez ajouter: ", i + 1);
                    scanf(" %d", &nombre);
                    if(mode == 1) insertNode(&tmp, createNode(nombre));
                    else insertAVL(&tmp, createNode(nombre));
                }
                if(mode == 1) root = mergeTreesIntoBST(root, tmp);
                else if(mode == 2) {
                    printf("\nEst-ce que chaque element du premier arbre est plus petit que n'importe quel element du deuxieme arbre?\nAppuyez 1 pour oui ou 2 pour non.\n>> ");
                    scanf(" %d", &nombre);
                    if(nombre == 1) root = joinAVL(root, tmp);
                    else root = mergeAVL(root, tmp);
                }
                break;

            case 9:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &nombre);
                if(mode == 1); // TODO
                else if(mode == 2) splitAVL(root, nombre, &T1, &T2);
                printTreePreOrder(T1);
                printTreePreOrder(T2);
                root = T1;
                break;

            case 10:
                printf("\nChoisissez le type de traversement:\nprecommande(1) ou dans l'ordre(2) ou post-commande(3) ou bien dans l'ordre de niveau(4)?\n>> ");
                scanf(" %d", &nombre);
                if(!(nombre == 1 || nombre == 2 || nombre == 3 || nombre == 4)) {
                    printf("\nMerci de faire un choix valable. Appuyez 1 pour traversee precommande, 2 pour traversee dans l'ordre et 3 pour traversee post-commande.");
                    while(!(nombre == 1 || nombre == 2 || nombre == 3 || nombre == 4)) {
                        printf("\n>> ");
                        scanf(" %d", &nombre);
                    }
                } printf("\n");
                if(nombre == 1) printTreePreOrder(root);
                else if(nombre == 2) printTreeInOrder(root);
                else if(nombre == 3) printTreePostOrder(root);
                else printTreeLevelOrder(root);
                printf("\n");
                break;

            case 11:
                deleteTree(&root);
                stop = true;
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}