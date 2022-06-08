#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

Arb *createNode(int data) {
    Arb *new = calloc(1, sizeof(Arb));
    if(new) {
        new->data = data;
        new->parent = new;
        new->right = NULL;
        new->left = NULL;
    } return new;
}

int getSize(Arb *root) {
    if(!root) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int getHeight(Arb *node) {
    if(!node) return -1;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight >= rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void insertNode(Arb **root, Arb *new) {
    if(!(*root)) {
        *root = new;
        return;
    } Arb *tmp = *root;
    if(tmp->data < new->data) {
        if(!tmp->right) new->parent = tmp;
        insertNode(&(tmp->right), new);
    } else if(tmp->data > new->data) {
        if(!tmp->left) new->parent = tmp;
        insertNode(&(tmp->left), new);
    } else printf("\nLes noeuds egals ne sont pas autorises\n");
}

int findMax(Arb *root, int max) {
    if(!root) {
        return max;
    }
    max = root->data;
    max = findMax(root->right, max);
    return max;
}

int findMin(Arb *root, int min) {
    if(!root) {
        return min;
    }
    min = root->data;
    min = findMin(root->left, min);
    return min;
}

Arb *search(Arb *root, int data) {
    Arb *tmp = root;
    for(; tmp != NULL; ) {
        if(tmp->data == data) break;
        else if(tmp->data < data) {
            tmp = tmp->right;
        } else tmp = tmp->left;
    } return tmp;
}

Arb *leftDescendant(Arb *node) {
    if(!node) return NULL;
    if(node->left == NULL) {
        return node;
    } return leftDescendant(node->left);
}

Arb *rightAncestor(Arb *node) {
    if(!node) return NULL;
    if(node->data <= node->parent->data) {
        return node->parent;
    } return rightAncestor(node->parent);
}

// The node in the tree with the next largest key
Arb *nextNode(Arb *node) {
    if(!node) return NULL;
    if(node->right != NULL) {
        return leftDescendant(node->right);
    } return rightAncestor(node);
}

Arb *rightmostChild(Arb *root) {
    if(root->right == NULL) return root;
    else return rightmostChild(root->right);
}

Arb *leftmostChild(Arb *root) {
    if(root->left == NULL) return root;
    else return leftmostChild(root->left);
}

int *rangeSearch(Arb *node, int x, int y) {
    int *list = calloc(getSize(node), sizeof(int));
    if(!list) exit(1);
    int i = 0;
    Arb* xNode = node;
    while(xNode->data != x) {
        if(xNode->data > x) {
            if(xNode->left != NULL)
                xNode = xNode->left;
            else break;
        } else {
            if(xNode->right != NULL)
                xNode = xNode->right;
            else break;
        }
    }

    while(xNode->data <= y) {
        if(xNode->data >= x) {
            list[i] = xNode->data;
            i++;
        } xNode = nextNode(xNode);
    } list[i] = INT_MIN;
    return list;
}

void deleteNode(Arb **root, int data) {
    Arb *node = search(*root, data);
    if(!node) return;
    if(*root) {
        if(node->right == NULL) {
            if(node->left) node->left->parent = node->parent;
            if(node->parent->right == node) node->parent->right = node->left;
            else if(node->parent->left == node) node->parent->left = node->left;
            else {
                if(node->left) node->left->parent = node->left;
                *root = node->left;
            }
        } else {
            Arb *tmp = nextNode(node);
            if(node->parent->right == node) node->parent->right = tmp;
            else if(node->parent->left == node) node->parent->left = tmp;
            else {
                *root = tmp;
            }
            if(tmp->parent != node) tmp->parent->left = tmp->right;
            if(tmp->right) tmp->right->parent = tmp->parent;
            if(*root != tmp) tmp->parent = node->parent;
            else tmp->parent = tmp;
            tmp->left = node->left;
            if(node->right != tmp) tmp->right = node->right;
            else tmp->right = node->right->right;
        } 
        free(node);
        node = NULL;
    } else printf("L'arbre est deja vide.\n");
}

void printTreeInOrder(Arb *root) {
    if(!root) return;
    printTreeInOrder(root->left);
    printf("%d ", root->data);
    printTreeInOrder(root->right);
}

void printTreePreOrder(Arb *root) {
    // if(!root) return;
    // printf("%d ", root->data);
    // printTreePreOrder(root->left);
    // printTreePreOrder(root->right);
    // COMMENTEZ CI-DESSUS ET DECOMMENTEZ CI-DESSOUS AFIN DE MIEUX COMPRENDRE L'ARBRE
    if(!root) {
        printf("empty\n");
        return;
    }
    printf("data: %d\n", root->data);
    printf("[ %d's l child ] ", root->data);
    printTreePreOrder(root->left);
    printf("[ %d's r child ] ", root->data);
    printTreePreOrder(root->right);
}

void printTreePostOrder(Arb *root) {
    if(!root) return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    printf("%d ", root->data);
}

void printTreeLevelOrder(Arb *root) {
    if(!root) return;
    Ll *queue = NULL;
    queue = push(queue, root);
    while(queue) {
        Arb *tmp = pop(&queue);
        printf("%d ", tmp->data);
        if(tmp->left) queue = push(queue, tmp->left);
        if(tmp->right) queue = push(queue, tmp->right);
    }
}

void deleteTree(Arb **root) {
    if(!(*root)) return;
    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

Arb *createBST(int *arr, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    Arb *tmp = createNode(arr[mid]);
    tmp->left = createBST(arr, start, mid - 1);
    if(tmp->left) tmp->left->parent = tmp;
    tmp->right = createBST(arr, mid + 1, end);
    if(tmp->right) tmp->right->parent = tmp;
    return tmp;
}

void convertBSTtoArr(Arb *node, int *arr, int *ind) {
    if(!node) return;
    convertBSTtoArr(node->left, arr, ind);
    arr[(*ind)++] = node->data;
    convertBSTtoArr(node->right, arr, ind);
}

int *mergeArrs(int *arr1, int* arr2, int s1, int s2) {
    int *merged = calloc(s1 + s2, sizeof(int));
    int i = 0, j = 0, k = 0;
    while(i < s1 && j < s2) {
        if(arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        } k++;
    } 

    while(i < s1)
        merged[k++] = arr1[i++];
    
    while(j < s2)
        merged[k++] = arr2[j++];

    return merged;
}

Arb *mergeTreesIntoBST(Arb *T1, Arb *T2) {
    int i = 0, s1 = getSize(T1);
    int *arr1 = calloc(s1, sizeof(int));
    convertBSTtoArr(T1, arr1, &i);

    int j = 0, s2 = getSize(T2);
    int *arr2 = calloc(s2, sizeof(int));
    convertBSTtoArr(T2, arr2, &j);

    int *merged = mergeArrs(arr1, arr2, s1, s2);
    return createBST(merged, 0, s1 + s2 - 1);
}