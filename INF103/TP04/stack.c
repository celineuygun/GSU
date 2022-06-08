#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
 * Parametre olarak verilen yigit
 * elemanini bellekten siler.
 * yigit zaten bos ise herhangi bir islem
 * yapmaz.
 */
void stack_free(struct stackNode **top) {
    struct stackNode *ttop = *top;
    while (ttop != NULL) {
        struct stackNode *orphan = ttop;
        ttop = ttop->next;
        free(orphan);
    }
    *top = NULL;
}

/*
 * Parametre olarak verilen yigit yapisinin
 * bos olup olmadini kontrol eder.
 * yigit bos ise 1, degilse 0 dondurur.
 */
int is_empty(struct stackNode *top){
   int result = 0;
   if(top == NULL)result = 1;
   return result;
}


/*
 * Parametre olarak verilen yigit yapisinda
 * yeni veri data yapisini ekler.
 * (LIFO prensibi ile)
 */
void stack_push(struct stackNode **top, double data) {
   struct stackNode *new = malloc(sizeof(struct stackNode));
   if(new==NULL)exit(EXIT_FAILURE);
   new->data = data;
   new->next = *top;
   *top = new;
}


/*
 * Parametre olarak verilen yigit yapisindan
 * ilk elemani siler.
 * Eger yigit bos ise -1 degerini gonderir.
 */
double stack_pop(struct stackNode **top) {
	double retval = -1;
    struct stackNode* tmp = *top;
    if(tmp!=NULL){
        retval = (*top)->data;
        *top = (*top)->next;
        free(tmp);
        return retval;
    }
    return retval;
}


/*
 * Parametre olarak verilen yigit yapisindan
 * k degeri kadar node siler,
 * silinen degerleri yigit olarak dondurur
 */ 
struct stackNode* stack_multi_pop(struct stackNode **top, int k){
    struct stackNode* tmp = *top;
    struct stackNode* retvals = *top;
    int i=0;
    if(*top!=NULL){
        while(*top!=NULL&&i<k){
            tmp=*top;
            *top=(*top)->next;
            ++i;
        }tmp->next=NULL;
         return retvals;
    }return NULL;
}

/*
 * Parametre olarak verilen yigit yapisini
 * ekrana basar.
 */
void stack_print(struct stackNode *top) {
    if(is_empty(top))printf("Yigit bos\n");
    else{
        struct stackNode* tmp = top;
        while(tmp!=NULL){
            printf("%.2f -> ", tmp->data);
            tmp=tmp->next;
        }printf("NULL\n");
    }
}