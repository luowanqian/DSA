#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int capacity = 256;
    int *arr = (int*)malloc(sizeof(int)*capacity);
    int n = 0;
    int heap_size = 0;
    int i;

    max_heap_insert(arr, &heap_size, capacity, 3);
    max_heap_insert(arr, &heap_size, capacity, 2);
    max_heap_insert(arr, &heap_size, capacity, 1);
    max_heap_insert(arr, &heap_size, capacity, 5);
    max_heap_insert(arr, &heap_size, capacity, 6);
    max_heap_insert(arr, &heap_size, capacity, 4);

    n = heap_size;
    for (i=0; i<n; i++) {
        printf("Maximum %d, Extract %d\n",
               heap_maximum(arr, heap_size),
               heap_extract_max(arr, &heap_size));
    }

    free(arr);

    return 0;
}
