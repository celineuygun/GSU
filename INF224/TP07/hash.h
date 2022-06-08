#ifndef HASH_H_
#define HASH_H_

#define MULTIPLIER 37
#define TABLE_SIZE 100

typedef struct key {
    int index;
    char *word;
    struct key *next, *prev;
} Key;

unsigned long hashCompute(const char *str);
Key* hashLookup(Key **table, const char *str);
void deleteTable(Key **table);
bool deleteKey(Key **table, char *str);
void insertKey(Key **table, char *str);
void printTable(Key **table);

#endif