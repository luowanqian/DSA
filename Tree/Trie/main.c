#include "trie.h"
#include <stdio.h>

int main()
{
    Trie *obj = trieCreate();

    trieInsert(obj, "apple");

    printf("%d\n", trieSearch(obj, "apple"));
    printf("%d\n", trieSearch(obj, "app"));
    printf("%d\n", trieStartsWith(obj, "app"));

    trieInsert(obj, "app");
    printf("%d\n", trieSearch(obj, "app"));

    trieFree(obj);

    return 0;
}
