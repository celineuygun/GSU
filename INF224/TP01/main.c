#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"

int main(void) {
    int response = 0, num = 0, num2 = 0, num3 = 0, *nums, capacity = 0, sumTotal = 0;
    int counterPrime = 0, counterNonPrime = 0;
    char c, c2, *s;
    bool stop = false, stop2 = false;

    while(stop != true) {
        printf("\nMENU:\n");
        printf("[0] QUITTER             [1]sum                [2]isLetter     [3]isDigit          [4]isVowel\n");
        printf("[5]isEven               [6]isPrime            [7]digitSum     [8]reverseNumber    [9]isUpperCase\n");
        printf("[10]upperCase           [11]downCase          [12]factoriel   [13]power           [14]findRoots\n");
        printf("[15]isPalindromeNumber  [16]isPalindromeText  [17] Fonctions de tableau d'entiers\n>> ");
        scanf(" %d", &response);

        switch(response) {
            case 0:
                stop = true;
                break;

            case 1:
                printf("\nCombien des nombres souhaitez-vous ajouter?\n>> ");
                scanf(" %d", &capacity);
                nums = calloc(capacity, sizeof(int));
                printf("\n");
                for(int i = 0; i < capacity; ++i) {
                    printf("Nombre %d: ", i);
                    scanf(" %d", &nums[i]);
                    if(i % 2 == 0) sumTotal += sum(nums[i - 1], nums[i]);
                } printf("\n\tLa somme est %d\n", sumTotal);
                free(nums);
                break;

            case 2:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                printf("\n\t%c %s\n", c, isLetter(c) ? "est une lettre" : "n'est pas une lettre");
                break;
                
            case 3:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                printf("\n\t%c %s\n", c, isDigit(c) ? "est un chiffre" : "n'est pas un chiffre");
                break;

            case 4:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                printf("\n\t%c %s\n", c, isVowel(c) ? "est une voyelle" : "n'est pas une voyelle");
                break;

            case 5:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("\n\t%d est un nombre %s\n", num, isEven(num) ? "pair" : "impair");
                break;

            case 6:
                printf("\nJusqu'a quel nombre souhaitez-vous trouver les nombres premiers?\n>> ");
                scanf(" %d", &num);
                counterNonPrime = 0, counterPrime = 0;
                for(int i = 1; i <= num; ++i) {
                    if(isPrime(i)) counterPrime++;
                    else counterNonPrime++;
                } printf("\tLa quantite totale de nombres premiers inferieurs a %d est %d et de nombres non premiers est %d\n", num, counterPrime, counterNonPrime);
                break;

            case 7:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("\n\tLa somme des chiffres du nombre %d est %d\n", num, digitSum(num));
                break;

            case 8:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("\n\tL'inverse du nombre %d est %d\n", num, reverseNumber(num));
                break;

            case 9:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                printf("\n\tLa lettre '%c' %s\n", c, isUpperCase(c) ? "est en majuscule" : "n'est pas en majuscule");
                break;

            case 10:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                c2 = c;
                upperCase(&c);
                printf("\n\tLa lettre '%c' en majuscule est '%c'\n", c2, c);
                break;

            case 11:
                printf("\nEntrez un caractere: ");
                scanf(" %c", &c);
                c2 = c;
                downCase(&c);
                printf("\n\tLa lettre '%c' en miniscule est '%c'\n", c2, c);
                break;

            case 12:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("\n\t%d factorielle vaut %d\n", num, factoriel(num));
                break;

            case 13:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("Entrez la puissance: ");
                scanf(" %d", &num2);
                printf("\n\t%d a la puissance %d vaut %d\n", num, num2, power(num, num2));
                break;

            case 14:
                printf("\nEntrez a, b et c dans la fonction ax^2 + bx + c = 0: ");
                scanf(" %d %d %d", &num, &num2, &num3);
                findRoots(num, num2, num3);
                break;

            case 15:
                printf("\nEntrez un nombre: ");
                scanf(" %d", &num);
                printf("\n\tLe nombre '%d' %s\n", num, isPalindromeNumber(num) ? "est palindrome" : "n'est pas palindrome");
                break;

            case 16:
                fflush(stdout);
                s = calloc(50, sizeof(char));
                printf("\nEntrez un texte: ");
                scanf(" %s", s);
                printf("\n\tLe texte '%s' %s\n", s, isPalindromeText(s, strlen(s)) ? "est palindrome" : "n'est pas palindrome");
                free(s);
                break;

            case 17:
                stop2 = false;
                printf("\nEntre la taille du tableau que vous souhaitez creer: ");
                scanf(" %d", &num);
                nums = calloc(num, sizeof(int));
                printf("\n");
                for(int i = 0; i < num; ++i) {
                    printf("Nombre %d: ", i);
                    scanf(" %d", &nums[i]);
                } 

                while(stop2 != true) {
                    printf("\n[0] RETOUR AU MENU      [1]exist              [2]getIndex     [3]count            [4]findMax\n");
                    printf("[5]findMax2             [6]findMin            [7]findMin2     [8]sumArray         [9]averageArr\n>> ");
                    scanf(" %d", &response);

                    switch(response) {
                        case 0:
                            stop2 = true;
                            free(nums);
                            break;
                        
                        case 1:
                            printf("\nEntrez le nombre que vous souhaitez chercher: ");
                            scanf(" %d", &num2);
                            printf("\n\t%d %s dans le tableau\n", num2, exist(nums, num, num2) ? "est" : "n'est pas");
                            break;
                        
                        case 2:
                            printf("\nEntrez le nombre dont l'indice vous souhaitez chercher: ");
                            scanf(" %d", &num2);
                            printf("\n\tL'indice de %d est %d dans le tableau\n", num2, getIndex(nums, num, num2));
                            break;
                        
                        case 3:
                            printf("\nEntrez un nombre: ");
                            scanf(" %d", &num2);
                            printf("\n\t%d apparait %d fois dans le tableau\n", num2, count(nums, num, num2));
                            break;
                        
                        case 4:
                            printf("\n\tLe nombre maximum de tableaux est %d\n", findMax(nums, num));
                            break;
                        
                        case 5:
                            printf("\n\tLe 2eme nombre maximum de tableaux est %d\n", findMax2(nums, num));
                            break;
                        
                        case 6:
                            printf("\n\tLe nombre minimum de tableaux est %d\n", findMin(nums, num));
                            break;
                        
                        case 7:
                            printf("\n\tLe 2eme nombre minimum de tableaux est %d\n", findMin2(nums, num));
                            break;
                        
                        case 8:
                            printf("\n\tLa somme des elements du tableau est %d\n", sumArray(nums, num));
                            break;
                        
                        case 9:
                            printf("\n\tLa moyenne du tableau est %.2lf\n", averageArr(nums, num));
                            break;

                        default:
                            printf("\nMerci de faire un choix valable.\n>> ");
                            break;
                    }
                } break;

            default:
                printf("\nMerci de faire un choix valable.\n");
                break;
        }
    } return 0;
}