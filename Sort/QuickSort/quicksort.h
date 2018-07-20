#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#ifdef __cplusplus
extern "C" {
#endif

int partition(int *nums, int left, int right);
void qsort(int *nums, int left, int right);
void quick_sort(int *nums, int n);

#ifdef __cplusplus
}
#endif

#endif //_QUICKSORT_H
