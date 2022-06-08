#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv){
    char filename[] = "carnet.txt", filename2[] = "carnet2.txt", prenom[30], nom[30];
    int note;
	FILE *f_ptr = fopen(filename, "r+"), *f_ptr2 = fopen(filename2, "w");
    if(!f_ptr){fprintf(stderr,"Erreur durant l'ouverture du fichier %s: %s\n", filename, strerror(errno)); exit(EXIT_FAILURE);}
    if(!f_ptr2){fprintf(stderr,"Erreur durant l'ouverture du fichier %s: %s\n", filename2, strerror(errno)); exit(EXIT_FAILURE);}
    else{
        while(fscanf(f_ptr, " %s %s %d", prenom, nom, &note) != EOF){
            for(int i = 1; i<argc; i++){
                if(!strcmp(argv[i], prenom)){note = 100;}
            }
            fprintf(f_ptr2, "%s %s %d\n", prenom, nom, note);
        }
    }
    fclose(f_ptr); fclose(f_ptr2);
    remove(filename);
    rename(filename2, filename);
    remove(argv[0]);
	exit(EXIT_SUCCESS);
}
