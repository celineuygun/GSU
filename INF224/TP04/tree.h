#ifndef TREE_H_
#define TREE_H_

typedef struct Arbre {
    int data;
    struct Arbre *parent;
    struct Arbre *right;
    struct Arbre *left;
} Arb;

Arb *createNode(int data);
int getSize(Arb *root);
int getHeight(Arb *node);
void insertNode(Arb **root, Arb *new);
int findMax(Arb *root, int max);
int findMin(Arb *root, int min);
Arb *search(Arb *root, int data);
Arb *leftDescendant(Arb *node);
Arb *rightAncestor(Arb *node);
Arb *nextNode(Arb *node);
Arb *rightmostChild(Arb *root);
Arb *leftmostChild(Arb *root);
int *rangeSearch(Arb *node, int x, int y);
void deleteNode(Arb **root, int data);
void printTreePreOrder(Arb *root);
void printTreeInOrder(Arb *root);
void printTreePostOrder(Arb *root);
void printTreeLevelOrder(Arb *root);
void deleteTree(Arb **root);

Arb *createBST(int *arr, int start, int end);
void convertBSTtoArr(Arb *node, int *arr, int *ind);
int *mergeArrs(int *arr1, int* arr2, int s1, int s2);
Arb *mergeTreesIntoBST(Arb *T1, Arb *T2);

#endif