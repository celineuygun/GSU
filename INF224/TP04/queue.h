#ifndef QUEUE_H_
#define QUEUE_H_
#include "tree.h"

typedef struct LinkedList {
    Arb *node;
    struct LinkedList *next;
} Ll;

Ll *push(Ll *list, Arb *node);
Arb *pop(Ll **list);

#endif