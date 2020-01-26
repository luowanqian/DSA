#include "insort.h"

void insertion_sort(int *nums, int n)
{
    int p, tmp;
    for (int i = 1; i < n; i++) {
        tmp = nums[i];
        for (p = i; p > 0 && nums[p - 1] > tmp; p--)
            nums[p] = nums[p - 1];
        nums[p] = tmp;
    }
}

