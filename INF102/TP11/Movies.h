/*
 * Movies.h
 *
 *      Author: Selin Uygun
 */

#ifndef _MOVIES_H_
#define _MOVIES_H_

typedef struct {
    char *name;
    char *director;
    int year;
    float imdb;
} movie;

int *SortIntegerArray (int *array, int n);
// Film listesini on tanimli olan film bilgileriyle doldurur.
void fillArray(movie *tab);

// Parametre olarak aldigi "movie" tipindeki yapinin tum alanlarini (isim, yonetmen, vizyon yili ve puani) ekrana bastirir.
void printInfo(movie m);

// Parametre olarak aldigi film listesinde yer alan filmlerin bilgilerini ekrana bastirir.
void printList(movie *m);

// Kullanici tarafindan ismi girilen filmi, parametre olarak aldigi film listesinde arar; bulursa filmin yonetmenini, vizyon yilini ve puanini ekrana bastirir. 
void searchByName(movie *m);

// Kullanici tarafindan ismi girilen yonetmenin film listesinde yer alan tum filmlerinin adini, vizyon yilini ve puanini ekrana bastirir. 
void searchByDirector(movie *m);

// Kullanici tarafindan girilen yilda vizyona girmis olan filmlerin adini, yonetmenini ve puanini ekrana bastirir. 
void searchByYear(movie *m);

// Film listesinde yer alan en yuksek puanli filmi bulup dondurur.
movie mostPopular(movie *m);

#endif // _MOVIES_H_