#include <stdio.h>

int maxPouls(int);
float imc(float, float);

int main()
{
    int x;
    float y, z;
    char selection = 'a';
    while(1){
        printf("\n**************************************");
        printf("\nEntrez l'age de l'individu: ");
        scanf(" %d", &x);
        printf("Max Pouls: %d\n", maxPouls(x));
        
        printf("\nEntrez le poids(kg) et la taille(m): ");
        scanf(" %f %f", &y, &z);
    
    
        float iimc = (imc(y, z));
    
        printf("IMC: %.2f ", iimc);
    
        if (iimc < 18.5){
            printf("(Maigre)\n");
        }else if (18.5 <= iimc && iimc <= 24.9){
            printf("(Normale)\n");
        }else if (24.9 <= iimc && iimc <= 29.9){
            printf("(Surpoids)\n");
        }else{
            printf("(Obese)\n");
        }
        
        printf("**************************************");

        printf("\nQ ou q- afin de quitter: ");
        scanf(" %c", &selection);
        if (selection == 'q' || selection == 'Q'){
            break;
        }
        
    }
    printf("\nAu revoir!!\n");
        
	return 0;
}

int maxPouls(int age){
    return 220 - age;
}
float imc(float m, float t){
    return m / (t * t);
}