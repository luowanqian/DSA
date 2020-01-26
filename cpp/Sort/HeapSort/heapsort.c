#include "heapsort.h"


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

void build_max_heap(int* arr, int n)
{
    int i;

    for (int i=n/2-1; i>=0; i--)
        max_heapify(arr, n, i);
}

void heap_sort(int* arr, int n)
{
    int i;
    int tmp;

    // build heap (rearrange array)
    build_max_heap(arr, n);

    // one by one extract an element from heap
    for (i=n-1; i>=0; i--) {
        // move current root to end
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;

        // call max heapify on the reduced heap
        max_heapify(arr, i, 0);
    }
}