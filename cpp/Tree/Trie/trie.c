#include "trie.h"
#include <stdlib.h>
#include <string.h>

/** Initialize your data structure here. */
Trie* trieCreate() {
    struct TrieNode *pNode = NULL;
    int i;

    pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (NULL != pNode) {
        pNode->isEndOfWord = false;
        pNode->n = 0;
        for (i=0; i<ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    int i, index;
    int len = strlen(word);
    struct TrieNode *pNode;

    if (NULL == obj || 0 == len)
        return;

    pNode = obj;
    for (i=0; i<len; i++) {
        index = word[i] - 'a';
        if (NULL == pNode->children[index]) {
            pNode->children[index] = trieCreate();
        }
        pNode->n = pNode->n + 1;
        pNode = pNode->children[index];
    }

    pNode->isEndOfWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    int i, index;
    int len = strlen(word);
    struct TrieNode *pNode = obj;

    if (NULL == obj || 0 == len)
        return false;

    for (int i=0; i<len; i++) {
        index = word[i] - 'a';
        if (NULL == pNode->children[index])
            return false;
        pNode = pNode->children[index];
    }

    return pNode->isEndOfWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    int i, index;
    int len = strlen(prefix);
    struct TrieNode *pNode = obj;

    if (NULL == obj || 0 == len)
        return false;

    for (i=0; i<len; i++) {
        index = prefix[i] - 'a';
        if (NULL == pNode->children[index])
            return false;
        pNode = pNode->children[index];
    }

    return true;
}

void trieFree(Trie* obj) {
    int i;

    if (NULL != obj) {
        for (i=0; i<ALPHABET_SIZE; i++)
            trieFree(obj->children[i]);
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */
