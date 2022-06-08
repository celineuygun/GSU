#ifndef FILE_H_
#define FILE_H_

typedef struct priorityQueue{
    int item;
    int priority;
    struct priorityQueue *next;
    struct priorityQueue *prev;
} Noeud;

void deleteFile(Noeud **queue);
void shiftLeft(Noeud **queue, Noeud *tmp);
void shiftRight(Noeud **queue, Noeud *tmp);
void insertEleFile(Noeud **queue, int item, int priority);
Noeud *getMaxFile(Noeud *queue);
void extractMaxFile(Noeud **queue);
void removeEleFile(Noeud **queue, int item);
void changePriorityFile(Noeud **queue, int item, int priority);
void displayFile(Noeud *queue);

#endif