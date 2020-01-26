#include "bubblesort.h"

void bubble_sort(int* nums, int n)
{
    int i, j, tmp;

    for (i=1; i<n; i++) {
        for (j=0; j<n-i; j++) {
            if (nums[j] > nums[j+1]) {
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
}
