#include"contactlist.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*
 * Menuyu yazdirir
 */
void menu(){
  printf("\nMENU:\n");
  printf("0: EXIT\n");
  printf("1: Liste olustur\n");
  printf("2: Liste yazdir\n");
  printf("3: Kisi bilgilerini ara\n");
  printf("4: Listeye kisi ekle\n");
  printf("5: Listede degisiklik yap\n");
  printf("6: Listeyi dosyaya aktar\n");
  printf("7: Listeden kisi sil\n");
  printf("8: Listeyi sil\n>> ");
}

/*
 * Parametre olarak verilen sayi kadar
 * elemani olan bir dizi ile bunu gosteren
 * ContactList tipinde değişken oluşturur.
 */
ContactList create_contact_list(int number){
    ContactList c;
    c.contact_list = calloc(number, sizeof(Contact));
    if(c.contact_list==NULL){
      exit(EXIT_FAILURE);
    }
    c.max_number = number;
    c.current_number = 0;
    printf("%d KISILIK LISTE ALANI AYRILDI\n", number);
    return c;
}

/*
 * Parametre olarak verilen listeye
 * yeni elemani ekler.
 */
void add_new_contact(ContactList* c,Contact new_cnt){
  if(c->current_number==c->max_number){
    c->contact_list = realloc(c->contact_list, ((c->max_number)+1) * sizeof(Contact));
    if(c->contact_list==NULL){exit(EXIT_FAILURE);}
    (c->max_number)++;
  }
  c->contact_list[c->current_number]= new_cnt;
  (c->current_number)++;
  printf("YENI KISI EKLENDI\n");
}

/*
 * Parametre olarak verilen
 * ContactList icindeki listeyi
 * ekrana basar.
 */
void print_contact_list(ContactList c){
  int i = 0;
  printf("\n========================\n");
  printf("===== KISI LISTESI =====\n");
  while(i!=c.current_number){
    printf("========================\n");
    printf("%d. Kisi\n", i+1);
    printf("ID NO: %d\nAdi: %s\nSoyadi: %s\nNumarasi: %s\n",
        c.contact_list[i].id, 
        c.contact_list[i].name, 
        c.contact_list[i].surname, 
        c.contact_list[i].tel_number);
    ++i;
  }
  printf("========================\n");
}

/*
 * Parametre olarak verilen
 * kisi listesinde istenen ismi arar
 * ve bilgilerini yazdirir
 */
void find_contact(ContactList *c, char* name, char* surname){
    int control = 0;
    for(int i=0; i<c->current_number; i++){
      if(!strcmp(c->contact_list[i].name,name) && !strcmp(c->contact_list[i].surname,surname)){
        printf("\nARADIGINIZ KISI LISTEDE BULUNUYOR\n");
        printf("========================\n");
        printf("======= BILGILER =======\n");
        printf("========================\n");
        printf("ID NO: %d\nNumarasi: %s\n========================\n",
            c->contact_list[i].id, 
            c->contact_list[i].tel_number);
            control = 1;
        break;
      }
    }
    if(!control){
      printf("\nARADIGINIZ KISI LISTEDE YOK\n"); 
    }
}

/*
 * Parametre olarak verilen
 * listeyi bellekten siler.
 */
void delete_contact_list(ContactList *c){
  free(c->contact_list);
  c->contact_list = NULL;
  printf("LISTE BASARIYLA SILINDI\n");
}

/*
 * Parametre olarak verilen
 * listeden listedeki secilen bir kisinin
 * secilen bir bilgisini degistir
 */
void change_info(ContactList *c, int kisi, int bilgi){
  printf("\nYERINI ALACAK BILGI: ");
  switch (bilgi){
    case 1:
      scanf("%d", &c->contact_list[kisi-1].id);
      break;
    case 2:
      scanf(" %[^\n]%*c", c->contact_list[kisi-1].name);
      break;
    case 3:
      scanf(" %[^\n]%*c", c->contact_list[kisi-1].surname);
      break;
    case 4:
      scanf(" %[^\n]%*c", c->contact_list[kisi-1].tel_number);
      break;
  }
  printf("DEGISIKLIK BASARILI\n");
}

/*
 * Parametre olarak verilen
 * listeden bir kisiyi siler
 */
void delete_contact(ContactList *c, char* name, char* surname){
  int control=0;
  for(int i=0; i<c->current_number; i++){
    if(!strcmp(c->contact_list[i].name, name) && !strcmp(c->contact_list[i].surname, surname)){ 
      for(; i<c->current_number-1; i++){
        c->contact_list[i] = c->contact_list[i+1];
      }
      c->current_number--;
      printf("KISI BASARIYLA SILINDI\n");
      control = 1;
      break;
    }
  }
  if(!control){
    printf("\nARADIGINIZ KISI LISTEDE YOK\n");
  }
}

/*
 * Parametre olarak verilen
 * listeyi istenen
 * dosyasya yazdirir
 */
void write_file(ContactList *c, char* fileName){
  FILE *f_ptr = fopen(fileName, "w");
  if(f_ptr == NULL){printf("\nDOSYA OLUSTURULURKEN SORUN YASANDI\n");exit(EXIT_FAILURE);}
  int i=0;
  fprintf(f_ptr, "=========================== CONTACT LIST ===========================\n");
  while(i<c->current_number){
    fprintf(f_ptr, "%-3d>> ID NO: %d NAME: %s SURNAME: %s TEL: %s\n",
     i+1, c->contact_list[i].id, c->contact_list[i].name, c->contact_list[i].surname, c->contact_list[i].tel_number);
    i++;
  }
  fclose(f_ptr);
  printf("KISI LISTESI %s ISIMLI DOSYAYA AKTARILDI\n", fileName);
}