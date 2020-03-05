/*
 * Hash Table
 * 解决冲突方法: Separate Chaining
 */


#include "hash_sep.h"
#include "hash.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define False 0

struct ListNode
{
    char* key;
    char* value;
    Position next;
};

typedef Position List;

struct HashTbl
{
    unsigned int table_size;
    List* table;
};


int is_prime(unsigned int n)
{
    unsigned int i, sqrt_n;

    if (n <= 1)
        return False;
    if (n <= 3)
        return TRUE;

    if ((n % 6 != 1) && (n % 6 != 5))
        return False;

    sqrt_n = (unsigned int)sqrt(n);
    for (i=5; i<=sqrt_n; i+=6) {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return False;
    }
    return TRUE;
}

unsigned int next_prime(unsigned int n)
{
    unsigned int prime;
    unsigned int found;

    if (n <= 1)
        return 2;

    prime = n;
    found = False;

    while (!found) {
        prime++;
        if (is_prime(prime))
            found = TRUE;
    }

    return prime;
}

HashTable initialize_table(unsigned int table_size)
{
    HashTable hash_table;
    int i;

    if (table_size < MIN_TABLE_SIZE) {
        fprintf(stderr, "Table size too small\n");
        exit(1);
    }

    // Allocate table
    hash_table = malloc(sizeof(struct HashTbl));
    if (NULL == hash_table) {
        fprintf(stderr, "Out of space!!!");
        exit(1);
    }

    hash_table->table_size = next_prime(table_size);

    // Allocate array of lists
    hash_table->table = malloc(sizeof(List) * hash_table->table_size);
    if (NULL == hash_table->table) {
        fprintf(stderr, "Out of space!!!");
        exit(1);
    }

    // Allocate list headers
    for (i=0; i<hash_table->table_size; i++) {
        hash_table->table[i] = malloc(sizeof(struct ListNode));
        if (NULL == hash_table->table[i]) {
            fprintf(stderr, "Out of space!!!");
            exit(1);
        } else {
            hash_table->table[i]->next = NULL;
        }
    }

    return hash_table;
}

void destroy_table(HashTable* hash_table_pointer)
{
    int i;
    Position curr, next;
    HashTable hash_table;

    if (NULL == hash_table_pointer)
        return;

    hash_table = *hash_table_pointer;
    if (NULL == hash_table)
        return;

    for (i=0; i<hash_table->table_size; i++) {
        curr = hash_table->table[i];
        while (NULL != curr) {
            next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(hash_table->table);
    free(hash_table);

    *hash_table_pointer = NULL;
}

unsigned int hash(char* str)
{
    hash_function hash_func;
    unsigned int hash_val;

    hash_func = hash_factory(BKDR_HASH);
    hash_val = hash_func(str, strlen(str));

    return hash_val;
}

Position find_position(HashTable hash_table, char* key)
{
    Position pos;
    List list;

    if (NULL == hash_table || NULL == key)
        return NULL;

    list = hash_table->table[hash(key) % hash_table->table_size];
    pos = list->next;

    while (pos != NULL && strcmp(key, pos->key) != 0)
        pos = pos->next;

    return pos;
}

char* find(HashTable hash_table, char* key)
{
    Position pos;

    pos = find_position(hash_table, key);
    if (NULL == pos)
        return NULL;

    return pos->value;
}

void insert(HashTable hash_table, char* key, char* value)
{
    Position pos, new_cell;
    List list;

    if (NULL == hash_table || NULL == key || NULL == value)
        return;

    pos = find_position(hash_table, key);
    if (NULL != pos) {  /* key is found */
        free(pos->value);
        pos->value = strdup(value);
    } else {            /* key is not found */
        new_cell = malloc(sizeof(struct ListNode));
        if (NULL == new_cell) {
            fprintf(stderr, "Out of space!!!");
            exit(1);
        }
        list = hash_table->table[hash(key) % hash_table->table_size];
        new_cell->next = list->next;
        new_cell->key = strdup(key);
        new_cell->value = strdup(value);
        list->next = new_cell;
    }
}
