#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkedlist.h"

int main(int argc, char *argv[]){
    int test[] = {5, 1024, 10, 20, 30, 100, 2048};
    int test1[] = {10, 20, 30};
    int tmp;

    struct node* llist;
    llist = create_sample_list();
    Print(llist);

    printf("Linked list ve dizi(test) ayni icerige %s\n", verifyList(llist, test)?"sahip":"sahip degil");
    printf("Linked list ve dizi(test1) ayni icerige %s\n", verifyList(llist, test1)?"sahip":"sahip degil");

    printf("Listenin uzunlugu: %d\n", Length(llist));

    Print(llist);

    Insert(&llist, test[0], 0);
    Insert(&llist, test[1], 1);
    Insert(&llist, test[5], 5);
    Insert(&llist, test[6], -1);

    Print(llist);

    GetAt(llist, 0, &tmp) ;
    printf("Donen deger %d \n",tmp );
    GetAt(llist, 6, &tmp);
    printf("Donen deger %d \n",tmp );

    int number = Count(llist, 5);
    printf("%d degerinden %d tane var\n", 5, number);

    int selection = 9;
    struct node* linkedlist;
    while(selection!=0){
        printf("\nMENU:\n0:EXIT\n1:Eleman ekle\n2:Listeyi yazdir\n3:Liste boyutunu yazdir\n4:Bir elemanin degerini geri dondur\n>>");
            scanf("%d", &selection);
        switch (selection){
            case 1:
                {
                int index, value;
                printf("Eklemek istediginiz index: ");
                scanf("%d", &index);
                printf("Eklemek istediginiz deger: ");
                scanf("%d", &value);
                Insert(&linkedlist, value, index);
                }
            break;
            case 2:
                Print(linkedlist);
                break;
            case 3:
                printf("Liste boyutu: %d\n", Length(linkedlist));
                break;
            case 4:
                {
                int index;
                printf("Geri dondurmek istediginiz elemanin indexi: ");
                scanf("%d", &index);
                GetAt(linkedlist, index, &tmp);
                printf("Donen deger %d \n", tmp);
                }
                break;
            default:
                if(selection!=0){
                printf("Gecerli bir secim yapin\n");
                }
                break;
        }
    }
    Free(linkedlist);
    Free(llist);
    return 0;
}
