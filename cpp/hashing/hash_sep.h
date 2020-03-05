#ifndef _HASH_SEP_H
#define _HASH_SEP_H

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

#define MIN_TABLE_SIZE 10

HashTable initialize_table(unsigned int table_size);
void destroy_table(HashTable* hash_table_pointer);
char* find(HashTable hash_table, char* key);
void insert(HashTable hash_table, char* key, char* value);

unsigned int next_prime(unsigned int n);

#ifdef __cplusplus
}
#endif

#endif //_HASH_SEP_H
