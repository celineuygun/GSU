#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

unsigned long hashCompute(const char *str) {
    unsigned long hash = 0;
    while(*str++) {
        hash = hash * MULTIPLIER + *str;
    } return hash % TABLE_SIZE;
}

Key* hashLookup(Key **table, const char *str) {
    unsigned long hash = hashCompute(str);
    Key *node = table[hash];
    for(Key *tmp = node; tmp != NULL; tmp = tmp->next)
        if(!strcmp(tmp->word, str))
            return tmp;
    return NULL;
}

void deleteTable(Key **table) {
    for(int i = 0; i < TABLE_SIZE; ++i) {
        Key *tmp = table[i];
        if(tmp)
            while(tmp->next != NULL) {
                Key* cur = tmp;
                tmp = tmp->next;
                free(cur->word);
                free(cur);
            }
        table[i] = NULL;
    }
}
bool deleteKey(Key **table, char *str) {
    unsigned long hash = hashCompute(str);
    Key *tmp = table[hash];
    while(tmp != NULL) {
        if(!strcmp(tmp->word, str)) {
            if(tmp->prev)
                tmp->prev->next = tmp->next;
            else {
                if(tmp->next)
                    tmp->next->prev = NULL;
                table[hash] = tmp->next;
            } free(tmp->word);
            free(tmp);
            tmp->word = NULL;
            tmp = NULL;
            return true;
        } tmp = tmp->next;
    } return false;
}

void insertKey(Key **table, char *str) {
    Key *new = calloc(1, sizeof(Key));
    if(new) {
        unsigned long hash = hashCompute(str);
        Key *node = table[hash];
        new->index = hash;
        new->word = calloc(strlen(str) + 1, sizeof(char));
        if(new->word) strcpy(new->word, str);
        new->next =  node;
        if(node) node->prev = new;
        new->prev = NULL;
        table[hash] = new;
    }
}

void printTable(Key **table) {
    if(!(*table)) {
        printf("\nNULL");
    }
    for(int i = 0; i < TABLE_SIZE; ++i) {
        if(table[i]) printf("\n[%3d] ", i);
        for(Key *tmp = table[i]; tmp != NULL; tmp = tmp->next)
            printf("%s ", tmp->word);
    } printf("\n");
}