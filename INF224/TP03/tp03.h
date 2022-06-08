#ifndef TP03_H_
#define TP03_H_

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} Ll;

typedef struct Tableau {
    int *tableau;
    int capacity;
    int head;
    int tail;
} Tab;

Tab *initTab(unsigned capacity);
int isFull(Tab *tab);
int isEmpty(Tab *tab);
void deleteTab(Tab **tab);
void printTab(Tab *tab);
void deleteLl(Ll **list);
void printLl(Ll *list);

void empilerTab(Tab *tab, int data);
int depilerTab(Tab *tab);

void enfilerTab(Tab *tab, int data);
int defilerTab(Tab *tab);

Ll *empilerLl(Ll *list, int data);
int depilerLl(Ll **list);

Ll *enfilerLl(Ll *list, int data);
int defilerLl(Ll **list);

#endif