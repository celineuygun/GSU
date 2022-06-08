#ifndef TREEAVL_H_
#define TREEAVL_H_
#include "tree.h"

Arb *leftRotateAVL(Arb *X);
Arb *rightRotateAVL(Arb *X);
void insertAVL(Arb **root, Arb *new);
void deleteNodeAVL(Arb **root, int data);
void rebalanceRight(Arb *node);
void rebalanceLeft(Arb *node);
void rebalanceTree(Arb **root, Arb *node);

Arb *mergeAVL(Arb *T1, Arb *T2);

Arb *joinAVL(Arb *T1, Arb *T2);
Arb *joinLeft(Arb *T1, Arb *T2);
Arb *joinRight(Arb *T1, Arb *T2);

void splitAVL(Arb *root, int k, Arb **T1, Arb **T2);

#endif