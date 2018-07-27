#ifndef DSA_HEAP_H
#define DSA_HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

int heap_maximum(int* arr, int n);
int heap_extract_max(int* arr, int* n);
void max_heap_insert(int* arr, int* n, int capacity, int key);

#ifdef __cplusplus
}
#endif

#endif //DSA_HEAP_H
