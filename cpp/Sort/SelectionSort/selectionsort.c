#include "selectionsort.h"

void selection_sort(int* nums, int n)
{
    int i, j, tmp, min_idx;

    for (i=0; i<n-1; i++) {
        min_idx = i;
        for (j=i+1; j<n; j++) {
            if (nums[j] < nums[min_idx])
                min_idx = j;
        }
        tmp = nums[i];
        nums[i] = nums[min_idx];
        nums[min_idx] = tmp;
    }
}
