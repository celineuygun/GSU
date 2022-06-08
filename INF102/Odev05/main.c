#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fo(x) for(int i=0;i<x;i++)
#define N 250
#define lg 100

int motcounter(char str[lg][N], int l){
    int i=0, m_counter=0, lg_counter=0;
    while(1){
        if(i==0){if(str[lg_counter][i]==10&&str[lg_counter][i+1]==0){lg_counter++; continue;}}
        if(str[lg_counter][i+1]==0){
            if(str[lg_counter][i]==10){
                if(str[lg_counter][i-1]==32){i=0; lg_counter++; continue;}
                else if(str[lg_counter][i-1]==46){i=0; m_counter++; lg_counter++; continue;}
            }else{m_counter++; lg_counter++; break;}
        }
        else if(str[lg_counter][i]==32){m_counter++;}
        ++i;
    }
    return m_counter;
}

int occurence(char str[lg][N], int c, int l){
    int i=0, le_counter=0, lg_counter=0;
    while(1){
        if(str[lg_counter][i+1]==0){
            if(str[lg_counter][i]==10){lg_counter++; i=0; continue;}
            else{lg_counter++; break;}
        }
        else if(str[lg_counter][i]==c||str[lg_counter][i]==c+32){le_counter++;}
        ++i;
    }
    return le_counter;
}

int main(int argc, char **argv){
	FILE *f_ptr = NULL, *f_ptr2 = NULL, *f_ptr3 = NULL;
    char line[N], linecopy[N], lines[lg][N];
    int l=0;
    char fnames[3][20]={"fichier.txt", "turingtest.txt", "stats.txt"};
    f_ptr = fopen(fnames[0], "r+");
    f_ptr2 = fopen(fnames[1], "w+");
    f_ptr3 = fopen(fnames[2], "w+");
    if(f_ptr==NULL){printf("Erreur durant l'ouverture du fichier %s\n", fnames[0]); exit(EXIT_FAILURE);}
    if(f_ptr2==NULL){printf("Erreur durant l'ouverture du fichier %s\n", fnames[1]); exit(EXIT_FAILURE);}
    if(f_ptr3==NULL){printf("Erreur durant l'ouverture du fichier %s\n", fnames[2]); exit(EXIT_FAILURE);}
    else{
        while(fgets(line, sizeof(line), f_ptr) != NULL){
            fo(N){
                if(line[i]<=126&&line[i]>=32)
                    linecopy[i]=line[i]-3;
                else if(line[i]==13 && line[i+1]==10){linecopy[i]=10; linecopy[i+1]=0; break;}
                else{linecopy[i]=line[i];}
            }
            fputs(linecopy, f_ptr2);
            strcpy(lines[l], linecopy);
            ++l;
        }
    }
    fprintf(f_ptr3, "Nom du fichier   : %s\n", fnames[1]);
    fprintf(f_ptr3, "Nombre de lignes : %d\n", l);
    fprintf(f_ptr3, "Nombre de mots   : %d\n", motcounter(lines, l));
    fprintf(f_ptr3, "Nombre d’occurence des lettres:\n");
    for(int p=65; p<=90; ++p){fprintf(f_ptr3, "%c et %c  :  %d\n", p, p+32, occurence(lines, p, l));}
    fclose(f_ptr); fclose(f_ptr2); fclose(f_ptr3);
    return EXIT_SUCCESS;
}