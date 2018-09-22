#ifndef DSA_TRIE_H
#define DSA_TRIE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int n;
} Trie;

Trie* trieCreate();
void trieInsert(Trie* obj, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* prefix);
void trieFree(Trie* obj);

#ifdef __cplusplus
}
#endif

#endif //DSA_TRIE_H
