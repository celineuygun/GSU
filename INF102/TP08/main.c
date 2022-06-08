#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main(int argc, char **argv){
	FILE *f_ptr = NULL, *f_ptr2 = NULL;
    int numbers = 0, sum=0, j=0;
    char prenom[N], nom[N], s;
    f_ptr = fopen("notlar.txt", "r+");
    f_ptr2 = fopen("temp.txt", "w+");
    if(f_ptr==NULL||f_ptr2==NULL){
         printf("Desole, pas possible d'ouvrir le fichier %s","notlar.txt");
         exit(1);
    }else{
        char line[100];
        while (fgets(line, sizeof(line), f_ptr)) {
            sscanf(line, " %s %s %d", prenom, nom, &numbers);
            for(int i=1; i<argc; ++i){if(!strcmp(argv[i],prenom)){numbers=100; break;}}
            fprintf(f_ptr2, "%s %s %d\n", prenom, nom, numbers);
            sum += numbers;
            ++j;
        }
        rewind(f_ptr2);
        while((s=fgetc(f_ptr2)) != EOF){printf("%c",s);}
        printf("Somme = %d\nMoyenne = %d\n", sum, sum/j);
    }
    fclose(f_ptr);
    fclose(f_ptr2);
}