#include"exam_string.h"

/* Bu fonksiyon verilen line metnini nokta, virgul ve
 * bosluk karakterlerinden ayirarak geriye kalan kelimeleri
 * string olarak geri dondurur. DIKKAT: Bu fonksiyonun
 * ayni satir icin birden fazla defa cagirilmasi gerekmektedir.
 * Ornek:
 * char line[] = "this is one.";
 * char *w = get_next_word(line); // w'nin icerisinde "this" yaziyor
 * char *w = get_next_word(line); // w'nin icerisinde "is" yaziyor
 * char *w = get_next_word(line); // w'nin icerisinde "one" yaziyor
 * char *w = get_next_word(line); // w NULL oldu cunku satiri tukettik.
 */
char* get_next_word(char *line) {
    static int called = 0;
    char *ref = NULL;
    if (called == 0) {
        ref = line;
    }

    char *tok = strtok(ref, "., ");
    if (tok) {
        called = 1;
    } else {
        called = 0;
    }
    return tok;    
}

/* Bu fonksiyon stream ile verilen dosya gostericisinden
 * s stringinin icerisine en fazla size-1 harflik
 * satir okumasi yapar. Daha sonra satir sonu karakterini
 * temizler. Okuma basarisiz olursa 0, basarili olursa 1
 * dondurur. 
 */
int my_getline(FILE *stream, char *s, int size) {
    char *ret = fgets(s, size, stream);
    char *p = strchr(s, '\n');
    if (p) {
        *p = '\0';
    }
    return ret != NULL;
}


/* 
 * Parametre liste icin hafizada acilan 
 * yeri bosaltir. Her eleman icin 
 * word degerine ayrilan hafizayi da bosaltir.
 */
void free_list(struct Node *list) {
    while (list) {
        struct Node *temp = list->next;
        free(list->word);
        free(list);
        list = temp;
    }
}

/*
 * Parametre olarak verilen kelimeyi 
 *    - listede yoksa listeye ekler, count degeri 1 yapar. 
 *    - listede varsa count degerini 1 arttirir.
 */
void add_key(struct Node **list, char *key) {
    int check = 0;
    struct Node *tmp = *list;
    for(; tmp != NULL; tmp = tmp->next){
        if(!strcmp(tmp->word, key)){
            tmp->count++;
            check = 1;
        }
    }if(!check){
        struct Node *new = calloc(1, sizeof(struct Node));
        new->word = calloc(20, sizeof(char));
        strcpy(new->word, key);
        new->count = 1;
        new->next = *list;
        *list = new;
    }
}

struct Node* swap(struct Node* first, struct Node* second){
    struct Node* tmp = second->next;
    second->next = first;
    first->next = tmp;
    return second;
}

void bubble_sort(struct Node** head, int count){
    struct Node** tmp;
    int swapped;
    for(int i = 0; i <= count; i++){
        tmp = head;
        swapped = 0;
        for(int j = 0; j < count - i - 1; j++) {
            struct Node *p1 = *tmp, *p2 = p1->next;
            if(p1->count < p2->count) {
                *tmp = swap(p1, p2);
                swapped = 1;
            }
            tmp = &(*tmp)->next;
        }
        if(swapped == 0) break;
    }
}



/*
 * Parametre olarak verilen listeyi 
 * ekrana sirali olarak basar. 
 * Her satirda sirasiyla liste elemanlari vardir.
 * Siralama icin yeni bir fonksiyon ekleyebilirsiniz. 
 */
void print_list(struct Node *list) {
    if(!list || list->count == 0 ) printf("Liste bos\n");
    else{
        struct Node* tmp = list;
        while(tmp != NULL){
            printf("%s, %d\n", tmp->word, tmp->count);
            tmp = tmp->next;
        }
    }
}

struct Node* search_first_ncharacters(struct Node *list, char* key, int n){
    struct Node *new = NULL, *tmp = list;
    for(; tmp != NULL; tmp = tmp->next){
        if(!strncmp(tmp->word, key, n)) add_key(&new, tmp->word);
    }
    return new;
}

/*
 * en uzun kelimeyi bulur
 */
char* en_uzun(struct Node *list){
    struct Node *tmp = list;
    char* word = tmp->word;
    int length = strlen(tmp->word);
    for(; tmp != NULL; tmp = tmp->next){
        if(tmp->next != NULL){
            if(length < strlen(tmp->next->word)){
                length = strlen(tmp->next->word);
                word = tmp->next->word;
            }
        }
    }return word;
}



/* BONUS
 * Parametre olarak verilen listeyi 
 * freqs.txt isimli bir dosyaya yazar. 
 * Her satirda sirasiyla liste elemanlari vardir.
 * Siralama icin yeni bir fonksiyon ekleyebilirsiniz. 
 */
void print_to_file(struct Node *list){
    FILE *fp = fopen("freqs.txt", "w");
    if(fp == NULL){printf("\nDOSYA OLUSTURULURKEN SORUN YASANDI\n");exit(EXIT_FAILURE);}
    struct Node *tmp = list;
    for(; tmp != NULL; tmp = tmp->next){
        fprintf(fp, "%s, %d\n", tmp->word, tmp->count);
    }
    fclose(fp);
    printf("LISTE freqs.txt ISIMLI DOSYAYA BASARIYLA AKTARILDI\n");
}
