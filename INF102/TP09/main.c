#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(){
    char filename[] = "liste.txt", filename2[] = "solde.txt", ligne[50], livre[50];
    int selection = 0;
    float pourcentage = 0.0,  prix = 0.0;
    FILE *f_ptr= fopen(filename, "r+"), *f_ptr2 = fopen(filename2, "w");
    if(!f_ptr){fprintf(stderr,"Erreur durant l'ouverture du fichier %s: %s\n", filename, strerror(errno)); exit(EXIT_FAILURE);
    if(!f_ptr2){fprintf(stderr,"Erreur durant l'ouverture du fichier %s: %s\n", filename2, strerror(errno)); exit(EXIT_FAILURE);}}
    else{
        while(selection != 3){
            rewind(f_ptr);
            printf("\nMenu:\n1: Affichage de la liste\n2: Mise a jour des prix\n3: Ciao\n>> ");
            scanf(" %d", &selection);
            if(selection == 1){
                printf("\nLa liste:\n");
                while(fgets(ligne, 50, f_ptr))
                    printf("%s", ligne);
            }else if( selection == 2){
                printf("Entrez le pourcentage: ");
                scanf(" %f", &pourcentage);
                while(fscanf(f_ptr, " %s %f", livre, &prix) != EOF){
                    fprintf(f_ptr2," %s %.2f\n", livre, prix*(1.0-pourcentage));
                }
                printf("Vous pouvez trouver les nouveaux prix dans le fichier %s\n", filename2);
            }
        }
        printf("\nAu plus tard!\n");
    }
    
    fclose(f_ptr); fclose(f_ptr2);
	return 0;
}