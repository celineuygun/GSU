#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node* next;
  int data;
};

// Liste sonuna eleman ekleme 
void add_node_end(struct Node* head,int i){
  struct Node* cur = head;
  while(cur->next){
    cur = cur->next;
  }
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = i ;
  cur->next = new_node;
  new_node->next = NULL;
}

// Listenin ortasina verilen indekse gore eleman ekleme 
void add_node_middle(struct Node* head,int index,int data){
  struct Node* cur = head;
  struct Node* tmp;
  int i = 0 ;
  while(cur->next){
    if (i==index){
      struct Node* new_node = malloc(sizeof(struct Node));
      new_node->data = data;
      tmp =cur->next;
      cur->next = new_node;
      new_node->next = tmp;
      return;
    }
    i++;
    cur = cur->next;
  }
  // indeks sayisi boyuttan buyuk olursa sona ekle
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = i ;
  cur->next = new_node;
  new_node->next = NULL;
}

// Listeden eleman silme
// Elemanlarin data degerlerine gore
void delete_node(struct Node* head, int i){
  struct Node* cur = head;
  struct Node* prev_cur = head;
  while(cur){
    if(cur->data==i){
      prev_cur->next = cur->next;
    }
    prev_cur = cur;
    cur = cur->next;
  }
}

// Listeyi ekrana basma
void print_list(struct Node* head){
  struct Node* cur = head;
  while(cur){
    printf("Data %d\n",cur->data);
    cur = cur->next;
  }
}


// Listenin boyutunu geri verir
int get_list_length(struct Node* head){
  struct Node* cur = head;
  int cnt = 0 ;
  while(cur){
    cnt++;
    cur=cur->next;
  }
  return cnt;
}

/* Verilen listenin, 2.parametrede verilen sayi degerinden 
 * buyuk degerler tasiyan alt listesini oluşturur
 */
struct Node* sub_list(struct Node* head,int k){
  struct Node* new_head = malloc(sizeof(struct Node));
  new_head->data=k;
  new_head->next=NULL;
  
  for(;head!=NULL;head=head->next){
    if(head->data>=k){
      add_node_end(new_head, head->data);
    }
  }
  return new_head;
}


/* Verilen iki listeyi ard arda olacak 
 * sekilde birlestirir. 
 */
struct Node* merge_list(struct Node* head1, struct Node* head2){
    struct Node* new_head=malloc(sizeof(struct Node));

  if(head1->data < head2->data){
    new_head->data = head1->data;
    new_head->next = NULL;
    head1=head1->next;
    for(;head1!=NULL;head1=head1->next)add_node_end(new_head, head1->data);
    for(;head2!=NULL;head2=head2->next)add_node_end(new_head, head2->data);
  } else{
    new_head->data = head2->data;
    new_head->next = NULL;
    head2=head2->next;
    for(;head2!=NULL;head2=head2->next)add_node_end(new_head, head2->data);
    for(;head1!=NULL;head1=head1->next)add_node_end(new_head, head1->data);
  }
   return new_head;
}

int main(){
  struct Node * head = malloc(sizeof(struct Node));
  head->data = 1 ;
  head->next = NULL;
  for(int i=0;i<10;i++){
    add_node_end(head,i);
  }
  print_list(head);
  
  int l = get_list_length(head);
  printf("Length %d \n",l);

  struct Node* new_head = sub_list(head,8);
  add_node_middle(head,5,-1);
  
  struct Node* new_head1 = merge_list(head,new_head);
 
  printf("***List 1***\n");
  print_list(head);
  printf("***List 2***\n");
  print_list(new_head);
  printf("***Merged List***\n");
  print_list(new_head1);
}