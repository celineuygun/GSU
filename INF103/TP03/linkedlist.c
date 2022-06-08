#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

/* 10, 20, 30 elemanlarindan olusan basit bir liste
 * olusturan fonksiyon. */
struct node* create_sample_list(void) {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    head = malloc(sizeof(struct node));
    if(head==NULL)exit(EXIT_FAILURE);
    second = malloc(sizeof(struct node));
    if(second==NULL)exit(EXIT_FAILURE);
    third = malloc(sizeof(struct node));
    if(third==NULL)exit(EXIT_FAILURE);

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    return head;
}

/* Bagli listenin elemanlarini ekrana yazdiran fonksiyon. */
void Print(struct node* head) {
  struct node* tmp = head;
  while(tmp!=NULL){
     printf("%d -> ",tmp->data);
     tmp = tmp->next;
  }
  printf("NULL\n");
}

/* Bir listenin belli bir icerige sahip olup olmadigini
 * dogrulayan test fonksiyonu. */
int verifyList(struct node* head, int *values) {
    struct node* tmp = head;
    while(tmp!=NULL){
       if(tmp->data==*values){
         tmp=tmp->next;
         values++;
       }else{
          return 0;
       }
    }
    return 1;
}

/* Parametre olarak verilen
 * head'in gosterdigi listede kac dugum oldugunu
 * hesaplayip geriye dondurun. */
int Length(struct node* head) {
   struct node* tmp = head;
   int counter=0;
   while(tmp!=NULL){
      counter++;
      tmp=tmp->next;
   }
   return counter;
}

/* Listenin herhangi bir yerine dugum ekleyen asagidaki
 * fonksiyonu doldurun.
 * position == 0 ise listenin basina,
 * position == -1 ise listenin sonuna,
 * position baska bir deger ise araya ekleme yapacaksiniz.
 * Ornegin liste
 *      5, 10, 15
 * dugumlerinden olussun.
 *
 * position == 0  ise yeni liste: 20, 5, 10, 15
 * position == -1 ise yeni liste: 5, 10, 15, 20
 * position == 1  ise yeni liste: 5, 20, 10, 15
 * olmalidir.
 */
void Insert(struct node** head, int new_value, int position) {
   struct node *tmp = *head, *tmp2;
   struct node* new = malloc(sizeof(struct node));
   if(new==NULL){exit(EXIT_FAILURE);}
   new->data=new_value;
   new->next=NULL;
   int current = 0;
   int length = Length(*head);
   if(tmp!=NULL){
      if(position==-1||position>=length){
         while(tmp->next!=NULL){
            tmp=tmp->next;
         }
         tmp->next=new;
      }else{
         if(position==0){
            new->next=*head;
            *head=new;
         }else{
           while(current<position-1){
               tmp=tmp->next;
               ++current;
            }
            tmp2 = tmp->next;
            tmp->next = new;
            new->next = tmp2;
         }
      }
   }else{
      *head=new;
   }
}

/* head'in gosterdigi listenin butun dugumlerini
 * free() ile temizler. */
void Free(struct node* head) {
   struct node* tmp = head;
   while(head!=NULL){
      tmp=tmp->next;
      free(head);
      head=tmp;
   }
}
/* position ile verilen pozisyondaki elemani *result
 * pointeriyla verilen yere yazin.
 * Eger olmayan bir pozisyon istendiyse fonksiyon 1 dondurmeli, liste sinirlari
 * dahilinde kalindi ve basarili olunduysa 0 dondurmelidir. */
int GetAt(struct node* head, int position, int *result) {
   struct node* tmp = head;
   int length = Length(head);
   int i=0;
   if(position<length){
      while(i!=position){
         tmp=tmp->next;
         i++;
      }
      *result=tmp->data;
      return 0;
   }else{
      return 1;
   }
}

/* Listede value degerinin kac defa
 * yer aldigini hesaplayip geri donduren fonksiyonu yazin. */
int Count(struct node* head, int value) {
  struct node* tmp = head;
  int counter=0;
  while(tmp->next!=NULL){
     if(tmp->data==value){
        counter++;
     }
     tmp=tmp->next;
  }
  return counter;
}