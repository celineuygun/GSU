#include "name.h"
#include<string.h>

/*
 * Parametre olarak verilen
 * veri yapisina bagli dizideki
 * elemanlari ekrana basar.
 */
void print_db(struct dbName d){
	int ind;
	for(ind=0;ind<d.currentSize;ind++){
        printf("%50s, %d \n",d.db[ind].name,d.db[ind].value);
	}
}

/*
 * Parametre olarak verilen dosyayi acar,
 * ve icindeki sirali elemanlari veri yapisina
 * bagli dizide saklar.
 */
void read_name_file(struct dbName* d,char* filename){
    FILE * fp=fopen(filename,"r");
    if(fp){
    	char line[MAXSIZE];
    	while(fgets(line,MAXSIZE,fp)!=NULL){
		  int i=0;
		  while(line[i]!='\n')i++;
		  line[i]='\0';
          strcpy(d->db[d->currentSize].name,line);
          d->currentSize = d->currentSize + 1;
    	}
    }
    fclose(fp);
}


/*
 * Deger dosyasini acip, icindeki sayilari
 * dizideki sirasi ile dizi elemanlarini gunceller.
 */
void read_value_file(struct dbName* d,char* filename){
    FILE * fp=fopen(filename,"r");
	char chValue[2];
	int i=0;
	if(fp){ 
		while(fgets(chValue,2,fp)!=NULL){
			d->db[i].value = atoi(chValue);
			i++;
		}
	}
	fclose(fp);
}

/*
 * Dogrusal arama islemini yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen isimi arar. Isim bulundugunda
 * dizideki yerini, isim yoksa -1 dondurur.
 */
int search_uniform(struct dbName d,char* name){
	for(int i=0; i<d.currentSize; ++i){
		int result = strncmp(d.db[i].name,name,strlen(name));
		if(!result)return i;
	}
	return -1;
}


/*
 * Ikili arama islemi yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen ismi ikili(binary) olarak
 * arar. Isim bulundugunda dizideki yerini,
 * isim yoksa -1 dondurur.
 */
int search_binary(struct dbName d,char* name){
	int head=0, tale=d.currentSize - 1, middle;
	while(head<=tale){
		middle = (head+tale)/2;
		int result = strncmp(d.db[middle].name,name,strlen(name));
		if(result==0)return middle;
		else if(result<0){
			head = middle+1;
		}else{
			tale = middle-1;
		}
	}
	return -1;
}

/*
 * Verilen dizide elemanlarin deger degiskenlerine bakarak diziyi
 * boler. Deger degiskeni 1 ise Good, deger degiskeni 0 ise Bad
 * olarak atanir.
 */
void split_names(struct dbName* dAll,struct dbName* dGood,struct dbName* dBad){
   int ind;
   for(ind=0;ind<dAll->currentSize;ind++){
	   if(dAll->db[ind].value == 1){
		   strcpy(dGood->db[dGood->currentSize].name,dAll->db[ind].name);
		   dGood->db[dGood->currentSize].value = dAll->db[ind].value;
		   dGood->currentSize++;
	   }else{
		   strcpy(dBad->db[dBad->currentSize].name,dAll->db[ind].name);
		   dBad->db[dBad->currentSize].value = dAll->db[ind].value;
		   dBad->currentSize++;
	   }
   }
}

/*
 * Verilen iki veri yapisinda ismi oncelikle ilk
 * veri yapisi dizisinde, sonra da ikinci veri yapisi
 * dizisinde arar. Isim bulunamadiginda -1, bulundugunda
 * yerini geri gonderir.
 */
int search_good_bad(struct dbName dGood, struct dbName dBad,char* name){
    int result = -1;
	result = search_binary(dGood, name);
	if(result!=-1){ 
		printf("%s is in the dGood.\n", name);
		return result;
	}
	result = search_binary(dBad, name);
	if(result!=-1)printf("\n%s is in the dBad.\n", name);
	return result;
}