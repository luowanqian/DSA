#include "quicksort.h"

int partition(int *nums, int left, int right)
{
    int i = left - 1;
    int tmp;
    int pivot = nums[right];
    for (int j = left; j <= right - 1; j++) {
        if (nums[j] <= pivot) {
            i = i + 1;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    i = i + 1;
    tmp = nums[i];
    nums[i] = pivot;
    nums[right] = tmp;

    return i;
}

void qsort(int *nums, int left, int right)
{
    if (left < right) {
        int p = partition(nums, left, right);
        qsort(nums, left, p - 1);
        qsort(nums, p + 1, right);
    }
}

void quick_sort(int *nums, int n)
{
    qsort(nums, 0, n - 1);
}
