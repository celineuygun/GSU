#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#define CREATE 1 
#define NCREATE 0

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Kullanim: %s <dosya_adi>\n", argv[0]);
        exit(1);
    }

    Key *w = NULL;
    char word[1024];

    Key *hash_table[MAXBUCKETS];
    memset(hash_table, 0, sizeof(hash_table));

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("%s dosyasi bulunamadi.\n", argv[1]);
        exit(1);
    }

    /* Sonsuz dongu icerisinde dosyadan kelime kelime
     * okuma yapalim. Okudugumuz kelimeyi hash'ta
     * arayalim yoksa ekleyelim. Son olarak elimize gecen
     * dugumun count uyesini 1 artiralim. */
    while (1) {
        if (fscanf(fp, "%s", word) != 1)
            break;

        w = hash_lookup(hash_table, word, CREATE);
        w->count++;
    }
    fclose(fp);

    printf("%d\n", hash_count_word(hash_table, "the"));
    hash_same_code(hash_table, "the");
    printf("%d\n", hash_count_word(hash_table, "months"));
    hash_same_code(hash_table, "months");
    
    /* 100'den az sayida gecen kelimeleri ekrana yazdir */
    hash_dump(hash_table, 100);
    
     int cnt_array[3] = {120,30,20};
 
    // for(int i=0; i<3; ++i){
    //      hash_dump(hash_table, cnt_array[i]);
    // }

    hash_free(hash_table);
    return 0;
}
