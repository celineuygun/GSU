#include <stdio.h>
#include <string.h>

int main(){
    char x[100];
    char c;
    int i;
    for(i=32; i<=126; i++) {printf("Decimal: %-3d   Caractere: %c \n", i, i);}

    printf("Entrez un caractere en miniscule: ");
    scanf("%c", &c);
    if(c >= 'a' && c <= 'z'){c = c - 32;}
    printf("En majuscule: %c\n", c);

    printf("Entrez une chaine de caractere: ");
	scanf(" %[^\n]%*c", x);
    
    printf("La longueur de la chaine \"%s\" est %lu", x, strlen(x));
    printf("\n");
    
	return 0;
}