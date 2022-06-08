#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include"exam_string.h"


int main(int argc, char *argv[]) {
    struct Node *list = NULL;
    char line[255];
    char *word;

    if(argc != 2){
        printf("Programi kullanmak icin dosya ismi ile calistirin.\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    while(my_getline(fp, line, 255)){
        while(1){
            word = get_next_word(line);
            if(!word) break;
            add_key(&list, word);
        }
    }
    fclose(fp);
    int list_size = 0;
    struct Node *tmp_count = list;
    while(tmp_count != NULL){
        tmp_count = tmp_count->next;
        list_size++;
    }
    bubble_sort(&list, list_size);
    print_list(list);

    struct Node* new = search_first_ncharacters(list, "imp", 3);
    printf("======= search_first_ncharacters =======\n");
    print_list(new);

    printf("======= en_uzun =======\n");
    printf("En uzun kelime: %s\n", en_uzun(list));

    printf("======= print_to_file =======\n");
    print_to_file(list);

    free_list(list);
    free_list(new); 
    return 0;
}
