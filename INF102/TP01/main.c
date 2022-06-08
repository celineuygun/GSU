#include <stdio.h>
#include <math.h>

int main()
{
    int a = 0;
    int b = 0;
    int h = 0;
    int x = 0;
    int resultat = 0;
    int coefficients[4];
    int puissances[3];

    printf("Cote 1 : ");
    scanf("%d", &a);
    printf("Cote 2 : ");
    scanf("%d", &b);
    printf("Hauteur: ");
    scanf("%d", &h);

    int surface = a * b;
    int laterale = (a * h + b * h) * 2;
    int totale = laterale + surface * 2;
    int volume = a * b * h;


    printf("\nLa surface de la base   : %d\n", surface);
    printf("La surface laterale     : %d\n", laterale);
    printf("La surface totale       : %d\n", totale);
    printf("Le volume               : %d\n", volume);
    printf("\n");

    printf("19x^3 + 28x^2 + 37x + 456 = ?\n");
    printf("Entrez un entier: ");
    scanf("%d", &x);
    resultat = 19 * pow(x, 3) + 28 * pow(x, 2) + 37 * x + 456;
    printf("Le resultat de l'equation est egal a %d quand x = %d\n", resultat, x);

    printf("\n?x^3 + ?x^2 + ?x + ? = ?\n");
    printf("Entrez un entier: ");
    scanf("%d", &x);
    printf("Entrez les coefficients de l’equation: ");
    scanf("%d %d %d %d", &coefficients[0], &coefficients[1], &coefficients[2], &coefficients[3]);
    printf("%dx^3 + %dx^2 + %dx + %d = ?\n", coefficients[0], coefficients[1], coefficients[2], coefficients[3]);
    resultat = coefficients[0] * pow(x, 3) + coefficients[1] * pow(x, 2) + coefficients[2] * x + coefficients[3];
    printf("Le resultat de l'equation est egal a %d quand x = %d et les coefficients sont = %d, %d, %d, %d respectivement\n", resultat, x, coefficients[0], coefficients[1], coefficients[2], coefficients[3]);

    printf("\n?x^? + ?x^? + ?x^? + ? = ?\n");
    printf("Entrez un entier: ");
    scanf("%d", &x);
    printf("Entrez les coefficients de l’equation: ");
    scanf("%d %d %d %d", &coefficients[0], &coefficients[1], &coefficients[2], &coefficients[3]);
    printf("Entrez les 3 puissances de l’equation: ");
    scanf("%d %d %d", &puissances[0], &puissances[1], &puissances[2]);
    printf("%dx^%d + %dx^%d + %dx^%d + %d = ?\n", coefficients[0], puissances[0], coefficients[1], puissances[1], coefficients[2], puissances[2], coefficients[3]);
    resultat = coefficients[0] * pow(x, puissances[0]) + coefficients[1] * pow(x, puissances[1]) + coefficients[2] * pow(x, puissances[2])+ coefficients[3];
    printf("Le resultat de l'equation est egal a %d quand x = %d, les coefficients sont = %d, %d, %d, %d et les puissances sont = %d, %d, %d respectivement\n", resultat, x, coefficients[0], coefficients[1], coefficients[2], coefficients[3], puissances[0], puissances[1], puissances[2]);

	return 0;
}