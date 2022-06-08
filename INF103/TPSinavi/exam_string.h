#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#ifndef EXAMSTRING_H_
#define EXAMSTRING_H_

struct Node {
  char*word;
  int count;
  struct Node *next;
};

int my_getline(FILE *stream,char*s,int size);
char* get_next_word(char *line);
void free_list(struct Node* list);
void add_key(struct Node **list,char *key);
void print_list(struct Node *list);
struct Node* search_first_ncharacters(struct Node *list, char* key, int n);
char* en_uzun(struct Node *list);
struct Node* swap(struct Node* first, struct Node* second);
void bubble_sort(struct Node** head, int count);
void print_to_file(struct Node *list);

#endif /* EXAMSTRING_H_ */
