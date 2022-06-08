/*
 * main.c
 *
 *      Author: Selin Uygun
 */

#include <stdio.h>
#include <stdlib.h>
#include "Movies.h"
#define L 20

int main(){
    int response = 0;
    movie mlist[L];
    fillArray(mlist);
    while(response != 6){
        printf("\nMenu:\n");
        printf(" [1] Display the movie list\n");
        printf(" [2] Search by name\n");
        printf(" [3] Search by director\n");
        printf(" [4] Search by release year\n");
        printf(" [5] Display the most popular movie on the list\n");
        printf(" [6] Exit\n");
        printf("\nEnter the code of the item: ");
        scanf("%d", &response);
        getchar(); 
        switch(response){
            case 1:
                printList(mlist);
                break;
            case 2:
                searchByName(mlist);
                break;
            case 3: 
                searchByDirector(mlist);
                break;
            case 4:
                searchByYear(mlist);
                break;
            case 5: 
                printf("THE MOST POPULAR MOVIE:\n");
                printInfo(mostPopular(mlist));
                break;
            case 6: 
                printf("Ciao!\n");
                break;
            default:
                printf("Invalid operation code, try again!\n"); 
        }
    }
    return 0;
}