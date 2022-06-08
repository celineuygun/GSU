#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

int main() {
    Key *table[TABLE_SIZE];
    memset(table, 0, sizeof(table));
    int response = 0;
    bool stop = false;
    char word[50];

    while(stop != true) {
        printf("\nMENU:\n");
        printf("Appuyez sur 1 pour inserer un element\n");
        printf("Appuyez sur 2 pour supprimer un element\n");
        printf("Appuyez sur 3 pour chercher un element\n");
        printf("Appuyez sur 4 pour afficher le base de donnees\n");
        printf("Appuyez sur 5 pour quitter le menu\n>> ");
        scanf(" %d", &response);

        switch (response) {
            case 1:
                printf("\nQuel mot voulez-vous ajouter?\n>> ");
                scanf(" %[^\n]%*c", word);
                insertKey(table, word);
                printf("\n%s a ete ajoute\n", word);
                break;

            case 2:
                printf("\nQuel mot voulez-vous supprimer?\n>> ");
                scanf(" %[^\n]%*c", word);
                if(deleteKey(table, word) == false) printf("\nIl n'y a pas de %s\n", word);
                else printf("\n%s a ete supprime\n", word);
                break;

            case 3:
                printf("\nQuel mot voulez-vous chercher?\n>> ");
                scanf(" %[^\n]%*c", word);
                Key *found = hashLookup(table, word);
                if(found) printf("\nLe mot %s se trouve a l'indice %d\n", word, found->index);
                else printf("\nIl n'y a pas de %s\n", word);
                break;
            
            case 4:
                printTable(table);
                break;

            case 5:
                stop = true;
                deleteTable(table);
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}