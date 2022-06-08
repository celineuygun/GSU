#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp02.h"

int main() {
    Personne *contactList = NULL;
    char *prenom, *nom, *info, *ville;
    long int numFixe = 0, numMobile = 0;
    int codeVille = 0;
    int response = 0, mode = 0;
    bool stop = false;

    printf("Choissisez un type de liste pour la liste de contacts.\n");
    printf("[1] lineaire unidirectionnelle\n[2] circulaire unidirectionnelle\n[3] linéaire bidirectionnelle\n[4] circulaire bidirectionnelle\n>> ");
    scanf("%d", &mode);
    while(mode < 1 || mode > 4) {
        printf("\nMerci de faire un choix valable.\n>> ");
        scanf(" %d", &mode);
    }

    while(stop != true) {
        printf("\nMENU:\nAppuyez sur 1 pour entrer un nouveau contact.\n");
        printf("Appuyez sur 2 pour supprimer le contact\n");
        printf("Appuyez sur 3 pour imprimer la liste des contacts.\n");
        printf("Appuyez sur 4 pour quitter le menu.\n>> ");
        scanf("%d", &response);
        
        switch (response) {
            case 1:
                fflush(stdin);
                Personne *p;
                prenom = calloc(20, sizeof(char));
                nom = calloc(20, sizeof(char));
                info = calloc(20, sizeof(char));
                ville = calloc(20, sizeof(char));
                printf("\nEntrez les informations du contact que vous souhaitez ajouter.\n");
                printf("Prenom: ");
                scanf(" %[^\n]%*c", prenom);
                printf("Nom: ");
                scanf(" %[^\n]%*c", nom);
                printf("Info: ");
                scanf(" %[^\n]%*c", info);
                printf("Ville: ");
                scanf(" %[^\n]%*c", ville);
                printf("Numero Fixe: ");
                scanf(" %ld", &numFixe);
                printf("Numero Mobile: ");
                scanf(" %ld", &numMobile);
                printf("Code Ville: ");
                scanf(" %d", &codeVille);
                p = initEle(prenom, nom, info, ville, numFixe, numMobile, codeVille);
                if(mode == 1) ajouterLU(&contactList, p);
                else if(mode == 2) ajouterCU(&contactList, p);
                else if(mode == 3) ajouterLB(&contactList, p);
                else if(mode == 4) ajouterCB(&contactList, p);
                free(prenom); free(nom); free(info); free(ville);
                break;
            
            case 2:
                fflush(stdin);
                printf("\nEntrez le prenom du contact que vous souhaitez supprimer\n>> ");
                scanf(" %s", prenom);
                if(mode == 1) supprimerEleLU(&contactList, prenom);
                else if(mode == 2) supprimerEleCU(&contactList, prenom);
                else if(mode == 3) supprimerEleLB(&contactList, prenom);
                else if(mode == 4) supprimerEleCB(&contactList, prenom);
                break;

            case 3:    
                printf("\nIl y a %d personnes dans cette liste de contacts\n", personCounter(0));
                if(mode == 1 || mode == 3)
                    for(Personne *tmp = contactList; tmp != NULL; tmp = tmp->next) {
                        afficherEle(tmp);
                    }
                else if(mode == 2 || mode == 4) {
                    Personne *tmp = contactList;
                    do {
                        if(!tmp) break;
                        afficherEle(tmp);
                        tmp = tmp->next;
                    } while(tmp != contactList);
                } break;

            case 4:
                if(mode == 1 || mode == 3) delList(&contactList, 1);
                else if(mode == 2 || mode == 4) delList(&contactList, 2);
                stop = true;
                break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    }
    return 0;
}