#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"name.h"

int main(int argc,char* argv[]){
    clock_t t,start;
    double time_taken;

    char* fname="TP07names.txt";
    char* vname="TP07values.txt";
    char* token="Zuzana";

    struct dbName* dname ;
    dname = malloc(sizeof(struct dbName));
    read_name_file(dname,fname);
    read_value_file(dname,vname);
    printf("\nDatabase\n");
    printf("=====================================================\n");
    print_db(*dname);

    start = clock();
    printf("\nUniform Search vs Binary Search\n");
    printf("=====================================================\n");
    printf("%d\n",search_uniform(*dname,token));
    t = clock() - start;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Dogrusal arama %f saniyede tamamladi.\n",time_taken);

    start = clock();
    printf("%d\n",search_binary(*dname,token));
    t = clock() - start;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("İkili arama %f saniyede tamamladi.\n",time_taken);

    start = clock();
    printf("%d\n",search_binary(*dname,"Janeen"));
    t = clock() - start;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Binary search takes %f second to run\n",time_taken);
    printf("=====================================================\n");

    struct dbName* dGood = malloc(sizeof(struct dbName));
    if(dGood==NULL){
        printf("Yer ayrilamadi.\n");
        exit(1);
    }
    dGood->currentSize = 0 ;
    struct dbName* dBad = malloc(sizeof(struct dbName));
    if(dBad==NULL){
        printf("Yer ayrilamadi.\n");
        exit(1);
    }
    dBad->currentSize = 0 ;
    
    split_names(dname,dGood,dBad);
    
    printf("\nGood\n");
    printf("=====================================================\n");
    print_db(*dGood);
    printf("\nBad\n");
    printf("=====================================================\n");
    print_db(*dBad);

    // printf("\nDatabase Search\n");
    // printf("=====================================================\n");
    // start = clock();
    // printf("Index: %d\n",search_good_bad(*dGood, *dBad,"Heloise"));
    // t = clock() - start;
    // time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("%f saniyede tamamladi.\n",time_taken);

    // start = clock();
    // printf("Index: %d\n",search_good_bad(*dGood, *dBad,"Karlyn"));
    // t = clock() - start;
    // time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("%f saniyede tamamladi.\n",time_taken);

    // start = clock();
    // printf("Index: %d\n",search_good_bad(*dGood, *dBad,"Kerrill"));
    // t = clock() - start;
    // time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("%f saniyede tamamladi.\n",time_taken);

    // start = clock();
    // printf("Index: %d\n",search_good_bad(*dGood, *dBad,"Zulema"));
    // t = clock() - start;
    // time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("%f saniyede tamamladi.\n\n",time_taken);

    free(dname);
    free(dGood);
    free(dBad);
    return 0 ;
}
