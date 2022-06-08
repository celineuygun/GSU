#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "patient.h"

const char *priority_strings[] = {
    "Heart attack",
    "Fracture",
    "Fever",
    "Nausea",
    "Sore throat",
    "Allergies",
};


/*
 * Parametre olarak verilen kuyruk yapisinin
 * elemanlarini ekrana basar.
 */
void print_queue(struct patientInfo *head) {
   if (!is_empty(head)) {
        printf("\nCurrent Queue:\n");
        printf("--------------\n");
        int i = 1;
        while (head) {
            printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i, priority_strings[head->prio], head->prio, head->ssn);
            head = head->next;
            i += 1;
        }
        printf("\n");
    }
}

/*
 * Parametre olarak verilen kuyrugun bos olup
 * olmadigini kontrol eder.
 * Bos ise 1 degilse 0 dondurur.
 */
int is_empty(struct patientInfo *head) {
    if(head==NULL){
        return 1;
    }
    return 0;
}

/* Parametre olarak verilen elemanlardan
 * yeni bir hasta olusturup
 * kuyruga ekler.
 * Hastanin guvenlik numarasi ve 
 * oncelik bilgisi fonksiyon parametreleridir. 
 */
struct patientInfo* enqueue(struct patientInfo *head, enum Priority prio, int ssn) {
    struct patientInfo* cur = head;
    struct patientInfo* tmp = NULL;
    struct patientInfo* new = malloc(sizeof(struct patientInfo));
    if(!new)exit(1);
    new->ssn = ssn;
    new->prio = prio;
    new->next = NULL;

    int inFor = 0, breaked = 0;
    if(head == NULL)return new;
    else{
        for(tmp=cur; cur->prio <= new->prio; cur=cur->next){
            tmp = cur;
            inFor = 1;
            if(cur->next==NULL){
                breaked = 1;
                break;
            }
        }
        if(breaked){cur->next=new; return head;}
        new->next = cur;
        if(inFor)tmp->next = new;
        else{return new;}
        return head;
    }
}


/*
 * Parametre olarak verilen kuyruktan ilk elemani siler
 * ve geri dondurur.
 */
struct patientInfo* dequeue(struct patientInfo **head) {
  if(*head==NULL){
      printf("Kuyruk zaten bos\n");
      exit(1);
  }else{
      struct patientInfo* first = *head;
      struct patientInfo* newHead = first;
      *head = (*head)->next;
      free(first);
      return newHead;
  }
}

/*
 * Parametre olarak verilen kuyruk yapisinin
 * icerisinden PRIO_FEVER onceligine sahip
 * hastalari alir ve baska bir kuyruk yapisina
 * koyarak geri dondurur.
 */
struct patientInfo* dequeueFever(struct patientInfo **head){
    struct patientInfo* new = NULL;
    struct patientInfo* cur = *head;
    struct patientInfo* tmp = *head;
    int inIf = 0;
    while(cur->next!=NULL){
        if(cur->prio == PRIO_FEVER){
            new = enqueue(new, cur->prio, cur->ssn);
            if(tmp!=cur)tmp->next = cur->next;
            else{*head=cur->next;}
            inIf=1;
        }
        if(inIf){
            cur = tmp->next;
            inIf=0;
        }
        else{
            tmp = cur;
            cur=cur->next;
        }
    }
    return new;
}

/*
 * Parametre olarak verilen kuyruk yapisinin
 * icerisinden parametre olarak verilen ssn'ye
 * sahip olan hastayi siler ve hastayi geri dondurur.
 */
struct patientInfo deadPatient(struct patientInfo **head, int ssn){
    struct patientInfo* cur = *head;
    struct patientInfo* tmp = *head;
    struct patientInfo patient;

    while(cur!=NULL){
        if(cur->ssn==ssn){
            patient.ssn = cur->ssn;
            patient.prio = cur->prio;
            patient.next = NULL;
            if(tmp!=cur)tmp->next = cur->next;
            else{*head=cur->next;}
            free(cur);
            cur = NULL;
            return patient;
        }
        tmp = cur;
        cur = cur->next;
    }
    printf("Hasta bulunamadi.\n");
    exit(1);
}

/*
 * Parametre olarak verilen kuyruk yapisinin
 * boyutunu geri dondurur.
 */
int queueLength(struct patientInfo *head){
    int counter = 0;
    while(head){
        counter++;
        head = head->next;
    }
    return counter;
}

/*
 * Parametre olarak verilen kuyruk yapisini
 * bellekten siler, bos ise herhangi bir islem
 * yapmaz.
 */
void queueFree(struct patientInfo **head){
    struct patientInfo *tmp = *head;

    while (tmp != NULL) {
        struct patientInfo *orphan = tmp;
        tmp = tmp->next;
        free(orphan);
    }
    *head = NULL;
}