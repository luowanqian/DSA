#include "hash_sep.h"
#include "hash.h"
#include <string.h>


int main(int argc, char* argv[])
{
//    char* key = "abcdefghijklmnopqrstuvwxyz1234567890";
    HashTable hash_table;
    int table_size = 20;

//    printf("General Purpose Hash Function Algorithms Test\n");
//    printf("By Arash Partow - 2002          \n"                 );
//    printf("Key:                          %s\n", key             );
//    printf(" 1. RS-Hash Function Value:   %u\n", hash_factory(RS_HASH)(key, 36));
//    printf(" 2. JS-Hash Function Value:   %u\n", hash_factory(JS_HASH)(key, 36));
//    printf(" 3. PJW-Hash Function Value:  %u\n", hash_factory(PJW_HASH)(key, 36));
//    printf(" 4. ELF-Hash Function Value:  %u\n", hash_factory(ELF_HASH)(key, 36));
//    printf(" 5. BKDR-Hash Function Value: %u\n", hash_factory(BKDR_HASH)(key, 36));
//    printf(" 6. SDBM-Hash Function Value: %u\n", hash_factory(SDBM_HASH)(key, 36));
//    printf(" 7. DJB-Hash Function Value:  %u\n", hash_factory(DJB_HASH)(key, 36));
//    printf(" 8. DEK-Hash Function Value:  %u\n", hash_factory(DEK_HASH)(key, 36));
//    printf(" 9. BP-Hash Function Value:   %u\n", hash_factory(BP_HASH)(key, 36));
//    printf("10. FNV-Hash Function Value:  %u\n", hash_factory(FNV_HASH)(key, 36));
//    printf("11. AP-Hash Function Value:   %u\n", hash_factory(AP_HASH)(key, 36));
//    printf("\n");

    /* Hash Table */
    hash_table = initialize_table(table_size);

    insert(hash_table, "A", "a");
    insert(hash_table, "B", "b");
    insert(hash_table, "C", "c");
    insert(hash_table, "D", "d");
    printf("Find key = \"A\": %s\n", find(hash_table, "A"));
    printf("Find key = \"B\": %s\n", find(hash_table, "B"));
    printf("Find key = \"C\": %s\n", find(hash_table, "C"));
    printf("Find key = \"D\": %s\n", find(hash_table, "D"));

    destroy_table(&hash_table);
    printf("Destory hash table\n");
    if (NULL == find(hash_table, "A"))
        printf("Find key = \"A\": not found\n");
    else
        printf("Find key = \"A\": found\n");

    return 0;
}
