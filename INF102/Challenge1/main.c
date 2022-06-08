#include <stdio.h>

int maxPouls(int);
float imc(float, float);
int dongu_yes();
int dongu_no();

char selection[3];
char yes[3] = {'o', 'u', 'i'}, no[3] = {'n', 'o', 'n'};

int main(){
    int x;
    float y, z;
    while(1){
        printf("\n**************************************");
        printf("\nEntrez l'age de l'individu: ");
        scanf(" %d", &x);
        printf("Max Pouls: %d\n", maxPouls(x));
        printf("\nEntrez le poids(kg) et la taille(m): ");
        scanf(" %f %f", &y, &z);
        
        float iimc = (imc(y, z));
        printf("IMC: %.2f ", iimc);
        if (iimc < 18.5){printf("(Maigre)\n");}
        else if (18.5 <= iimc && iimc <= 24.9){printf("(Normale)\n");}
        else if (24.9 <= iimc && iimc <= 29.9){printf("(Surpoids)\n");}
        else{printf("(Obese)\n");}
        printf("**************************************");
        printf("\nVoulez-vous quitter? oui ou non: ");
        scanf(" %c %c %c", &selection[0], &selection[1], &selection[2]);
        
        int dongu_y = dongu_yes();
        int dongu_n = dongu_no();
        if (dongu_y == 2){break;}
        else if(dongu_n == 2){continue;}
    }
    printf("\nAu revoir!!\n");
	return 0;
}
int maxPouls(int age){return 220 - age;}
float imc(float m, float t){return m / (t * t);}
int dongu_yes(){
    int i = 0, counter_yes = 3;
    while(i < 3){
        if(selection[i] == yes[i]){counter_yes--;}
        if (counter_yes == 0){return i;}
        ++i;
    }
    return 0;
}

int dongu_no(){
    int i = 0;
    int counter_no = 3;
    while(i < 3){            
        if (selection[i] == no[i]){counter_no--;}
        if (counter_no == 0){return i;}
        ++i;
    }
    return 0;
}