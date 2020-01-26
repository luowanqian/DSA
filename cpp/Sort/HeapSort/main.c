#include <stdio.h>
#include "heapsort.h"

int main()
{
    int i;
    int nums[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Array: ");
    for (i=0; i<n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    // heap sort
    heap_sort(nums, n);
    printf("Sorted array: ");
    for (i=0; i<n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
