#include <stdio.h>
#include "quicksort.h"

int main()
{
    int nums[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i=0; i<n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    quick_sort(nums, n);

    for (int i=0; i<n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}