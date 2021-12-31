#ifndef SORT_H
#define SORT_H

/*** Headers ***/
#include <stdlib.h>
#include <stdio.h>


/*** Functions ***/
void print_array(const int *array, size_t size);
void Swap(int *a, int *b);
void heapify(int *array, int n, size_t size, int i);
void heap_sort(int *array, size_t size);

#endif
