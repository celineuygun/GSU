#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contactlist.h"

int main(int argc,char** argv){
  int selection=1, listExists=0;
  ContactList list;
  char name[N], surname[N];

  while (selection!=0){
    menu();
    scanf("%d", &selection);

    if(selection==1){ // 1: Liste olustur
      if(listExists){
        printf("!! DAHA ONCEDEN BIR LISTE OLUSTURDUN !!\n");
        printf("!! DIGER SECENEKLERI DENE !!\n");
      }else{
        int default_size;
        printf("LISTENIN ILK BOYUTUNU GIRIN: ");
        scanf("%d", &default_size);
        list = create_contact_list(default_size);
        listExists = 1;
      }
    }
    else if(selection==2&&listExists){ // 2: Liste yazdir
      print_contact_list(list);
    }
    else if(selection==3&&listExists){ // 3: Kisi bilgilerini ara
      if(list.current_number){
        printf("\nARAMAK ISTEDIGINIZ KISININ SIRASIYLA ADINI VE SOYADINI GIRINIZ\n");
        printf("Ad: ");
        scanf(" %[^\n]%*c", name);
        printf("Soyad: ");
        scanf(" %[^\n]%*c", surname);
        find_contact(&list, name, surname);
      }else{
        printf("!! LISTE BOS !!\n");
      }
    }
    else if(selection==4&&listExists){  // 4: Listeye kisi ekle
      Contact n;
      printf("\nLISTEYE EKLEMEK ISTEDIGINIZ KISININ BILGILERINI GIRINIZ\n");
      printf("Ad: ");
      scanf(" %[^\n]%*c", n.name);
      printf("Soyad: ");
      scanf(" %[^\n]%*c", n.surname);
      printf("Numara: ");
      scanf(" %[^\n]%*c", n.tel_number);
      printf("ID: ");
      scanf("%d", &n.id);
      add_new_contact(&list, n);
    }
    else if(selection==5&&listExists){ // 5: Listede degisiklik yap
      int kisi, bilgi;
      print_contact_list(list);
      printf("\nDEGISIKLIK YAPMAK ISTEDIGINIZ KISI NUMARASI: ");
      scanf("%d", &kisi);
      while(kisi>list.current_number){
        printf("\n!! LUTFEN GECERLI BIR SECIM YAPIN !!\n>> ");
        scanf("%d", &kisi);
      }
      printf("\nDEGISIKLIK YAPMAK ISTEDIGINIZ BILGIYI SECIN\n");
      printf("1: ID NO\n2: Adi\n3: Soyadi\n4: Numarasi\n>> ");
      scanf("%d", &bilgi);
      while(bilgi>4){
        printf("\n!! LUTFEN GECERLI BIR SECIM YAPIN !!\n>> ");
        scanf("%d", &bilgi);
      }
      change_info(&list, kisi, bilgi);
    }
    else if(selection==6&&listExists){ // 6: Listeyi dosyaya aktar
      char dosyaIsmi[N], txtFile[]=".txt";
      printf("\nLISTENIN YAZILACAGI DOSYA ISMINI GIRINIZ\n");
      scanf(" %[^\n]%*c", dosyaIsmi);
      while(strstr(dosyaIsmi, txtFile) == NULL){
        printf("\n!! LUTFEN DOSYAYI .txt UZANTILI OLARAK GIRIN !!\n>> ");
        scanf(" %[^\n]%*c", dosyaIsmi);
      }
      write_file(&list, dosyaIsmi);
    }
    else if(selection==7&&listExists){ // 7: Listeden kisi sil
      printf("\nSILMEK ISTEDIGINIZ KISININ SIRASIYLA ADINI VE SOYADINI GIRINIZ\n");
      printf("Ad: ");
      scanf(" %[^\n]%*c", name);
      printf("Soyad: ");
      scanf(" %[^\n]%*c", surname);
      delete_contact(&list, name, surname);
    }
    else if(selection==8&&listExists){ // 8: Listeyi sil
      char e_h;
      printf("LISTEYI SILMEK ISTEDIGINIZDEN EMIN MISINIZ? (e/h): ");
      scanf(" %c", &e_h);
      if(e_h == 'e' || e_h == 'E'){
        delete_contact_list(&list);
        listExists = 0;
      }
    }
    else if(selection!=0){ // 0: EXIT
      char char_selection = selection + '0';
      if(strchr("12345678", char_selection)!=NULL){
        printf("!! ONCELIKLE BIR LISTE OLUSTURMALISIN !!\n");
        continue;
      }
      printf("!! LUTFEN GECERLI BIR SECIM YAP !!\n");
    }
  }

  if(listExists)delete_contact_list(&list);
  return 0;
}