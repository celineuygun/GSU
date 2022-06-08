#include "treeAVL.h"
#include <stdio.h>

int getBalance(Arb *node) {
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Arb *leftRotateAVL(Arb *X) {
    if(!X || !X->right) return X;
    Arb *P = X->parent, *Y = X->right, *B = Y->left;
    if(B && !Y->right && !X->left) { // Case X = 20 Y = 31 B = 30
        if(P != X) {
            B->parent = P;
            if(P->right == X) P->right = B;
            else P->left = B;
        } else B->parent = B;
        B->right = Y;
        B->left = X;
        Y->left = NULL;
        X->right = NULL;
        return B;
    }
    if(P != X) { // If X isn't the root node
        Y->parent = P;
        if(P->right == X) P->right = Y;
        else P->left = Y;
    } else Y->parent = Y; // If X is the root node, now Y becomes the root
    X->parent = Y;
    Y->left = X;
    if(B) B->parent = X;
    X->right = B;
    return Y;
}

Arb *rightRotateAVL(Arb *Y) {
    if(!Y || !Y->left) return Y;
    Arb *P = Y->parent, *X = Y->left, *B = X->right;
    if(B && !X->right && !Y->left) {
        if(P != Y) {
            B->parent = P;
            if(P->right == Y) P->right = B;
            else P->left = B;
        } else B->parent = B;
        B->right = X;
        B->left = Y;
        X->left = NULL;
        Y->right = NULL;
        return B;
    }
    if(P != Y) { // If Y isnt't the root node
        X->parent = P;
        if(P->right == Y) P->right = X;
        else P->left = X;
    } else X->parent = X; // If Y is the root node, now X becomes the root
    Y->parent = X;
    X->right = Y;
    if(B) B->parent = Y;
    Y->left = B;
    return X;
}

void insertAVL(Arb **root, Arb *new) {
    insertNode(root, new); // Inserting node to binary tree as usual
    Arb *cur = search(*root, new->data);
    rebalanceTree(root, cur);
}

void deleteNodeAVL(Arb **root, int data) {
    Arb *cur = search(*root, data), *next = nextNode(cur);
    deleteNode(root, data);
    rebalanceTree(root, next);
}

void rebalanceTree(Arb **root, Arb *node) {
    if(!(*root)) return;
    Arb *parent = node->parent;
    int balance = getBalance(node);
    if(balance > 1) // Left Heavy
        rebalanceRight(node);
    else if(balance < -1) // Right Heavy
        rebalanceLeft(node);
    if(node->parent == node) *root = node;
    else rebalanceTree(root, parent);
}

void rebalanceRight(Arb *node) {
    int balance = getBalance(node->left);
    if(balance < 0)
        node->left = leftRotateAVL(node->left); // Left Right Case
    node = rightRotateAVL(node); // Left Left Case
}

void rebalanceLeft(Arb *node) {
    int balance = getBalance(node->right);
    if(balance > 0)
        node->right = rightRotateAVL(node->right); // Right Left Case
    node = leftRotateAVL(node); // Right Right Case
}

Arb *mergeAVL(Arb *T1, Arb *T2) {
    if(!T1 || !T2)
        return (!T1 ? T2 : T1);
    int diff = getHeight(T1) - getHeight(T2);
    if(diff > 0) {
        while(T2) {
            int data = T2->data;
            deleteNode(&T2, data);
            insertAVL(&T1, createNode(data));
        } return T1;
    }
    else {
        while(T1) {
            int data = T1->data;
            deleteNode(&T1, data);
            insertAVL(&T2, createNode(data));
        } return T2;
    }
}

/*
 * This function requires that all elements in the first tree
 * are less than all elements in the second tree.
 * Time complexity: O(logn)
 */
Arb *joinAVL(Arb *T1, Arb *T2) {
    if(!T1 || !T2)
        return (!T1 ? T2 : T1);
    int diff = getHeight(T1) - getHeight(T2);
    if(diff > 0)
        return joinLeft(T1, T2);
    else
        return joinRight(T1, T2);
}

Arb *joinLeft(Arb *T1, Arb *T2) {
    int sub_h1 = getHeight(T1);
    int leftmost = (leftmostChild(T2))->data;
    deleteNodeAVL(&T2, leftmost);
    int new_h2 = getHeight(T2);
    Arb *tmp = T1, *cur =T1;
    if(new_h2 == -1) new_h2++;
    while(sub_h1 > new_h2 + 1) {
        if(getBalance(cur) == 1) sub_h1 -= 2;
        else sub_h1--;
        tmp = cur;
        cur = cur->right;
    }

    Arb *new = NULL;
    insertNode(&new, createNode(leftmost));
    new->left = cur;
    new->right = T2;
    cur->parent = new;
    if(T2) T2->parent = new;

    if(tmp == cur) {
        T1 = new;
        new->parent = new;
    } else {
        tmp->right = new;
        new->parent = tmp;
    }
    rebalanceTree(&T1, cur);
    return T1;
}

Arb *joinRight(Arb *T1, Arb *T2) {
    int sub_h2 = getHeight(T2);
    int rightmost = (rightmostChild(T1))->data;
    deleteNodeAVL(&T1, rightmost);
    int new_h1 = getHeight(T1);
    Arb *tmp = T2, *cur =T2;
    if(new_h1 == -1) new_h1++;
    while(sub_h2 > new_h1 + 1) {
        if(getBalance(cur) == -1) sub_h2 -= 2;
        else sub_h2--;
        tmp = cur;
        cur = cur->left;
    }

    Arb *new = NULL;
    insertNode(&new, createNode(rightmost));
    new->right = cur;
    new->left = T1;
    if(T1) T1->parent = new;

    if(tmp == cur) {
        T2 = new;
        new->parent = new;
    } else {
        tmp->left = new;
        new->parent = tmp;
    }
    rebalanceTree(&T2, cur);
    return T2;
}

/*
 * Returns 2 AVL trees such that all values lower than 
 * or equal to k are in T1 and the rest are in T2.
 */
void splitAVL(Arb *root, int k, Arb **T1, Arb **T2) {
    if(!root) {
        *T1 = NULL;
        *T2 = NULL;
        return;
    }
    //FIXME

    // if(k <= root->data) {
    //     splitAVL(root->left, k, T1, T2);
    // } else if(k > root->data) {
    //     splitAVL(root->right, k, T1, T2);
    // }

    // Arb *tmp = root->right;
    // if(root->parent->left == root) root->parent->left = NULL;
    // else root->parent->right = NULL;
    // root->parent = root;
    // if(tmp) {
    //     tmp->parent = tmp;
    //     *T2 = joinAVL(*T2, tmp);
    // } 
    // if(k == root->data && !root->left && !root->right) *T1 = joinAVL(*T1, root);
    // else *T1 = joinAVL(root, *T1);
}
