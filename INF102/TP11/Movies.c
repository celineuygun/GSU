/*
 * Movies.c
 *
 *      Author: Selin Uygun
 */

#include "Movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define L 20
int i;

void fillArray(movie *tab){
    tab[0].name = "Star Wars: Episode IV - A New Hope";
    tab[0].director = "George Lucas";
    tab[0].year = 1977;
    tab[0].imdb = 8.7;

    tab[1].name = "Star Wars: Episode V - The Empire Strikes Back";
    tab[1].director = "Irvin Kershner";
    tab[1].year = 1980;
    tab[1].imdb = 8.8;

    tab[2].name = "Star Wars: Episode VI - Return of the Jedi";
    tab[2].director = "Richard Marquand";
    tab[2].year = 1983;
    tab[2].imdb = 8.3;

    tab[3].name = "Star Wars: Episode I - The Phantom Menace";
    tab[3].director = "George Lucas";
    tab[3].year = 1999;
    tab[3].imdb = 6.5;

    tab[4].name = "Star Wars: Episode II - Attack of the Clones";
    tab[4].director = "George Lucas";
    tab[4].year = 2002;
    tab[4].imdb = 6.6;

    tab[5].name = "Star Wars: Episode III - Revenge of the Sith";
    tab[5].director = "George Lucas";
    tab[5].year = 2005;
    tab[5].imdb = 7.6;

    tab[6].name = "Star Wars: Episode VII - The Force Awakens";
    tab[6].director = "J.J. Abrams";
    tab[6].year = 2015;
    tab[6].imdb = 8.0;

    tab[7].name = "Rogue One: A Star Wars Story";
    tab[7].director = "Gareth Edwards";
    tab[7].year = 2016;
    tab[7].imdb = 7.8;

    tab[8].name = "Star Wars: Episode VIII - The Last Jedi";
    tab[8].director = "Rian Johnson";
    tab[8].year = 2017;
    tab[8].imdb = 7.2;

    tab[9].name = "Solo: A Star Wars Story";
    tab[9].director = "Ron Howard";
    tab[9].year = 2018;
    tab[9].imdb = 7.0;

    tab[10].name = "Star Wars: Episode IX - The Rise of Skywalker";
    tab[10].director = "Ron Howard";
    tab[10].year = 2019;
    tab[10].imdb = 7.0;

    tab[11].name = "LOTR: The Fellowship of the Ring";
    tab[11].director = "Peter Jackson";
    tab[11].year = 2001;
    tab[11].imdb = 8.8;

    tab[12].name = "LOTR: The Two Towers";
    tab[12].director = "Peter Jackson";
    tab[12].year = 2002;
    tab[12].imdb = 8.7;

    tab[13].name = "LOTR: The Return of the King";
    tab[13].director = "Peter Jackson";
    tab[13].year = 2003;
    tab[13].imdb = 8.9;

    tab[14].name = "Princess Mononoke";
    tab[14].director = "Hayao Miyazaki";
    tab[14].year = 1997;
    tab[14].imdb = 8.4;

    tab[15].name = "Spirited Away";
    tab[15].director = "Hayao Miyazaki";
    tab[15].year = 2001;
    tab[15].imdb = 8.6;

    tab[16].name = "Howl's Moving Castle";
    tab[16].director = "Hayao Miyazaki";
    tab[16].year = 2004;
    tab[16].imdb = 8.2;

    tab[17].name = "The Girl Who Leapt Through Time";
    tab[17].director = "Mamoru Hosoda";
    tab[17].year = 2006;
    tab[17].imdb = 7.8;

    tab[18].name = "Paprika";
    tab[18].director = "Satoshi Kon";
    tab[18].year = 2006;
    tab[18].imdb = 7.7;
    
    tab[19].name = "Your Name";
    tab[19].director = "Makoto Shinkai";
    tab[19].year = 2016;
    tab[19].imdb = 8.4;
}

// Parametre olarak aldigi "movie" tipindeki yapinin tum alanlarini (isim, yonetmen, vizyon yili ve puani) ekrana bastirir.
void printInfo(movie m){printf("===================================\nName: %s\nDirector: %s\nYear: %d\nIMDB: %.1f\n", m.name, m.director, m.year, m.imdb);}

// Parametre olarak aldigi film listesinde yer alan filmlerin bilgilerini ekrana bastirir.
void printList(movie *m){for(int i=0; i<L; i++){printf("%d ", i+1);printInfo(m[i]);}}

// Kullanici tarafindan ismi girilen filmi, parametre olarak aldigi film listesinde arar; bulursa filmin yonetmenini, vizyon yilini ve puanini ekrana bastirir. 
void searchByName(movie *m){
    char mname[N];
    int check = 0;
    printf("\nEnter Movie Name: ");
    scanf(" %[^\n]%*c", mname);
    for(int i=0; i<L; ++i){if(strstr(m[i].name, mname)){printInfo(m[i]);check++;}}
    if(check == 0){printf("Nope, it’s not on the list!\n");}
}

// Kullanici tarafindan ismi girilen yonetmenin film listesinde yer alan tum filmlerinin adini, vizyon yilini ve puanini ekrana bastirir. 
void searchByDirector(movie *m){
    char mdirector[N];
    int check = 0;
    printf("\nEnter The Director: ");
    scanf(" %[^\n]%*c", mdirector);
    for(int i=0; i<L; ++i){if(strstr(m[i].director, mdirector)){printInfo(m[i]);check++;}}
    if(check == 0){printf("Nope, it’s not on the list!\n");}
}

// Kullanici tarafindan girilen yilda vizyona girmis olan filmlerin adini, yonetmenini ve puanini ekrana bastirir. 
void searchByYear(movie *m){
    int myear, check = 0;
    printf("\nEnter The Year: ");
    scanf(" %d", &myear);
    for(int i=0; i<L; ++i){if(myear == m[i].year){printInfo(m[i]);check++;}}
    if(check == 0){printf("Nope, it’s not on the list!\n");}
}

// Film listesinde yer alan en yuksek puanli filmi bulup dondurur.
movie mostPopular(movie *m){
    float popular = m[0].imdb;
    int j=0;
    for(int i=1; i<L; ++i){if(popular < m[i].imdb){popular = m[i].imdb; j=i;}}
    return m[j];
}