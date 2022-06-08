#include <stdio.h>
#include <ctype.h>
#include <string.h>
int fonksiyonlar(int f(int c), char *str);
char *enmaj(char *str);
char *enmin(char *str);
int mystrlen(char *str);
char *mystrcpy(char *src, char *dest);
char *mystrcat(char *src, char *dest);
char *mystrstr(char *str, char *c);
#define N 100

char selection[3];
const char yep[] = "oui", no[] = "non";

char lastchaine[N];

int main(){
    char str1[] = "Human-robot interaction is the study of interactions between humans and robots. It is often referred as HRI by researchers. Human-robot interaction is a multidisciplinary field with contributions from human-computer interaction, artificial intelligence, robotics, natural language understanding, design, humanities and social sciences.";
    char str2[N], str3[N], str4[N], str5[N];
    printf("%s", str3);
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("LA CHAINE DES CARACTERES:\n%s\n", str1);
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("Majuscule    : %-3d\n", fonksiyonlar(isupper, str1));
    printf("Miniscule    : %-3d\n", fonksiyonlar(islower, str1));
    printf("Alphabetique : %-3d\n", fonksiyonlar(isalpha, str1));
    printf("Numerique    : %-3d\n", fonksiyonlar(isdigit, str1));
    printf("Espace       : %-3d\n", fonksiyonlar(isspace, str1));
    printf("Ponctuation  : %-3d\n", fonksiyonlar(ispunct, str1));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("Tout en majuscules:\n%s\n", enmaj(str1));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("Tout en miniscules:\n%s\n", enmin(str1));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("ENTREZ UNE CHAINE DES CARACTERES:\n");
    scanf(" %[^\n]%*c", str2);
    printf(">>La longueur de la chaine: %d\n", mystrlen(str2));
    printf(">>La copie de votre chaine: %s\n", mystrcpy(str3, str2));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("ENTREZ UNE DEUXIEME CHAINE POUR LA CONCATENATION (sans l'espace au debut):\n");
    scanf(" %[^\n]%*c", str4);
    printf(">>La longueur de la deuxieme chaine: %d\n", mystrlen(str4));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("VOULEZ-VOUS UN ESPACE DANS LA CONCATENATION AVANT DE LA DEUXIEME CHAINE?\noui ou non: ");
    scanf("%s", selection);
    printf(">>La concatenation: %s\n", mystrcat(str2, str4));
    printf("———————————————————————————————————————————————————————————————————————————\n");
    printf("ENTREZ UN CARACTERE: ");
    scanf(" %[^\n]%*c", str5);
    char *c_ptr = mystrstr(str2, str5);
    if(c_ptr == NULL){printf(">>Il n'y a pas de '%s' dans cette chaine.\n", str5);}
    else{printf(">>%s\n", c_ptr);}
    printf("———————————————————————————————————————————————————————————————————————————\n");
	return 0;
}
int fonksiyonlar(int f(int c), char *str){
    int size = 0;
    for(int i=0; i < mystrlen(str); ++i){if(f(str[i])){++size;}}
    return size;
}
char *enmaj(char *str){
    for(int i=0; i < mystrlen(str); ++i){if(str[i] >= 'a' && str[i] <= 'z'){str[i] -= 32;}}
    return str;
}
char *enmin(char *str){
    for(int i=0; i < mystrlen(str); ++i){if(str[i] >= 'A' && str[i] <= 'Z'){str[i] += 32;}}
    return str;
}
int mystrlen(char *str){
    int i = 0;
    while(str[i] != '\0'){++i;}
    return i;
}
char* mystrcpy(char *src, char *dest){
    int i = 0;
    while(dest[i] != '\0'){src[i] = dest[i]; ++i;}
    src[mystrlen(dest)] = '\0';
    return src;
}
char* mystrcat(char *src, char *dest){
    int i = mystrlen(src), j = 0, size_src = i; 
    if(!strcmp(selection, yep)){
        int size = (mystrlen(src) + mystrlen(dest) + 1);
        while(i < size){
            if(i == size_src){src[i] = ' ';}
            else{src[i] = dest[j]; j++;}
            ++i;
            src[size] = '\0';
        }
    }else if(!strcmp(selection, no)){
        int size = (mystrlen(src) + mystrlen(dest));
        while(i < size){src[i] = dest[j]; j++; ++i;}
        src[size] = '\0';
    }
    return src;
}
char* mystrstr(char *str, char *c){
    int j=0, size = mystrlen(str), counter = mystrlen(c), c_counter = counter;
    int continued = 0;
    for(int i=0; i<size; ++i){
        for(int j=0, l=i; counter>0 ; ++j, ++l){
            if(str[l] == c[j]){continued = 1; --counter;}
            else{continued = 0; j=0; counter=c_counter; break;}
        }if(continued){j = i; break;}
    }
    if(j != 0){ 
        int p = j;
        for(int m=0; j<size; ++m){str[m] = str[j]; ++j;}
        str[size-p] = '\0';
        return str;
    }
    return NULL;
}