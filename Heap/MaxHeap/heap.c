#include "heap.h"
#include <stdio.h>

int max_heap_parent(int i)
{
    return (i - 1) / 2;
}

int max_heap_left(int i)
{
    return 2 * i + 1;
}

int max_heap_right(int i)
{
    return 2 * i + 2;
}

void max_heapify(int* arr, int n, int i)
{
    int tmp;
    int largest = i;
    int left = max_heap_left(i);
    int right = max_heap_right(i);

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != i) {
        tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        // recursively heapify the affected sub-tree
        max_heapify(arr, n, largest);
    }
}

int heap_maximum(int* arr, int n)
{
    if (NULL == arr) {
        fprintf(stderr, "Array is NULL\n");
        return -1;
    }

    if (n < 1) {
        fprintf(stderr, "Heap underflow\n");
        return -1;
    }

    return arr[0];
}

int heap_extract_max(int* arr, int* n)
{
    int heap_max;

    if (NULL == arr || NULL == n) {
        fprintf(stderr, "Parameter arr or n is NULL\n");
        return -1;
    }

    if (*n < 1) {
        fprintf(stderr, "Heap underflow\n");
        return -1;
    }

    heap_max = arr[0];
    arr[0] = arr[*n-1];
    (*n)--;
    max_heapify(arr, *n, 0);

    return heap_max;
}

void heap_increase_key(int* arr, int i, int key)
{
    int tmp;

    if (NULL == arr) {
        fprintf(stderr, "Array is NULL\n");
        return;
    }

    if (arr[i] > key) {
        fprintf(stderr, "New key is smaller than current key\n");
        return;;
    }

    arr[i] = key;
    while (i > 0 && arr[max_heap_parent(i)] < arr[i]) {
        tmp = arr[i];
        arr[i] = arr[max_heap_parent(i)];
        arr[max_heap_parent(i)] = tmp;

        i = max_heap_parent(i);
    }
}

void max_heap_insert(int* arr, int* n, int capacity, int key)
{
    if (NULL == arr || NULL == n) {
        fprintf(stderr, "Parameter arr or n is NULL\n");
        return;
    }

    if (*n >= capacity) {
        fprintf(stderr, "Heap overflow\n");
        return;
    }

    (*n)++;
    heap_increase_key(arr, (*n)-1, key);
}
