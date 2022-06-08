#include <stdio.h>

void rectangle(int, int);
int maximum(int, int, int);

int main()
{
    int x, y, z;
    printf("Enter 2 integers: ");
    scanf("%d %d", &x, &y);
    rectangle(x, y);
    
    
    printf("\nEnter 3 integers: ");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    maximum(x, y, z);
    
    return 0;
}

void rectangle(int ligne, int colonne){
    int i, j;
    for (i = 0; i < ligne; ++i){
        for (j = 0; j < colonne; ++j){
            printf("*");
        }
        printf("\n");
        }
}
int maximum(int a, int b, int c){
    int numbers[3];
    numbers[0] = a;
    numbers[1] = b;
    numbers[2] = c;
    int largest = numbers[0];
    int i;
    for (i = 1; i < 3; ++i){
        if (numbers[i] > largest){
            largest = numbers[i];
        }
    }
    printf("Largest number is %d\n", largest);
    
}