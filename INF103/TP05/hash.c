#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"hash.h"
#define MULTIPLIER 31 

/* Stringler icin basit bir hash hesaplama fonksiyonu.
 * Her harfin ASCII degeri, onceki hash degerinin bir
 * carpanina ekleniyor.
 * Ornegin: "abcde" stringi icin:
 * ascii degerleri : a=97, b=98,c=99,d=100,e=101 
 *  h0 = 0 * 31 + 97 = 97
 *  h1 = h0 * 31 + 98 = 3105
 *  h2 = h1 * 31 + 99 = 96354
 *  h3 = h2 * 31 + 100 = 2987074
 *  h4 = h3 * 31 + 101 = 92599395
 *  92599395 % MAXBUCKETS (1000) = 395
 */
unsigned long hash_compute(const char *str){
  unsigned long hash = 0;
  while(*str){
    hash = (hash*MULTIPLIER) + *str;
    ++str;
  }
  return hash % MAXBUCKETS;
}

/* Her elemani bir bagli liste gostericisi olan table
 * dizisi parametre olarak veriliyor. Bu table dizisi
 * aslinda hash veriyapisini temsil eder.
 *
 * str ile verilen string hash'te var ise adresi
 * dondurulur. Yoksa ve create == 1 ise, hash
 * veriyapisina bu string eklenir.
*/
Key* hash_lookup(Key **table,const char *str,int create){
  unsigned long hash = hash_compute(str);
  Key* hash_node = table[hash];
  Key* cur = NULL;
  for(cur = hash_node; cur != NULL; cur=cur->next){
    if(!strcmp(cur->word,str)){
      return cur;
    }
  }

  if(create){
    cur = malloc(sizeof(Key));
    if(cur){
      cur->count = 0;
      cur->word = strdup(str);
      cur->next = hash_node;
      table[hash] = cur;
      return cur;
    }
   }
  return NULL;
}


/* Verilen hash tablosunda aynı  
 * hash koda sahip kac tane kelime olduğunu  
 * geri döndürür. 
*/
int hash_count_word(Key **table,const char *str){
  int cnt=0; 
  unsigned long hash = hash_compute(str);
  Key* cur = table[hash];
  while(cur->next!=NULL){
    cnt++;
    cur=cur->next;
  }
  return cnt;
}

/* Verilen hash tablosunda aynı  
 * hash koda sahip kelimeleri ekrana basar. 
*/
void hash_same_code(Key **table,const char *str){
  unsigned long hash = hash_compute(str);
  Key* cur = table[hash];
  while(cur->next!=NULL){
    printf("%s, ", cur->word);
    cur=cur->next;
  }
  printf("\n");
}

/* count parametresi <= n olan kelimeleri ekrana
 * yazdiran fonksiyon. 
 */
void hash_dump(Key **table,int n){
  Key *k;
  for(int i=0;i<MAXBUCKETS;++i){
    for(k=table[i];k!=NULL;k=k->next){
      if(k->count<=n){
	printf("%30s --> %5ld\n",k->word,k->count);
       }
     }
  }
}

/* table ile verilen hash veriyapisini
 * isletim sistemine iade eden fonksiyon.
 */
void hash_free(Key **table){
  for(int i=0;i<MAXBUCKETS;++i){
    Key* cur = table[i];
    if(cur){
      while(cur->next!=NULL){
        Key* tmp = cur;
        cur=cur->next;
        free(tmp->word);
      }
      table[i] = NULL;
    }
  }
}