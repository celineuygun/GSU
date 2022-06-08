#include <stdio.h>

int main()
{
    int x, y, i;
    int somme = 0;
    printf("\n>Entrez 2 entiers: ");
    scanf("%d %d", &x, &y);
    if (x == y){
        printf("\n%d est egal a %d", x, y);
    }else{
        printf("\n%d n’est pas egal a %d", x, y);
        if (x < y){
            printf("\n%dest plus petit que %d", x, y);
        }else{
            printf("\n%d est plus grand que %d", x, y);
        }
    }
    if (x % y == 0)
        printf("\n%d est un multiple de %d", x, y);
    printf("\nLeur somme est %d\n", x + y);
    
    printf("\n>Entrez un entier: ");
    scanf("%d", &i);
    int j = i;
    printf("\n");
    while(i >= 0){
        printf("%d ", i);
        --i;
    }
    printf("\n");
    while(i+1 <= j){
        printf("%d ", i+1);
        ++i;
    }
    printf("\n");
    
    printf("\n>Entrez un entier positif: ");
    scanf("%d", &j);
    i = j - 1;         // i = 14 j = 15
    while(j > 0){
        somme += j;
        --j;           // j = -1
    }
    printf("\n");
    while(j+1 < i+1){
        printf("%d + ", j + 1);
        ++j;          // j = 14
    }
    printf("%d = %d\n", i + 1, somme);
    
    printf("\n>Entrez la valeur limite: ");
    scanf("%d", &x);
    printf("\n");
    while(x > 0){
        if(x % 7 ==0){
            printf("%d ", x);
        }
        --x;
    }
    
    return 0;
}