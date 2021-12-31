#include "sort.h"
/**
 * Swap - Function that swaps two integers
 * @a: first intege
 * @b: second integer
 */

void Swap(int *a, int *b)
{
	int empty;

	empty = *a;
	*a = *b;
	*b = empty;
}


/**
 * heapify - Heap a subtree
 *
 * @array: array
 * @n: size
 * @size: size_t
 * @i: index
 * Return: void
 */
void heapify(int *array, int n, size_t size, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		Swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, size, largest);
	}
}


void heap_sort(int *array, size_t size)
{
	int i;

	if (array)
	{
		for (i = size / 2 - 1; i >= 0; i--)
			heapify(array, size, size, i);

		for (i = size - 1; i > 0; i--)
		{
			Swap(&array[0], &array[i]);
			print_array(array, size);
			heapify(array, i, size, 0);
		}
		Swap(&array[0], &array[i]);
		heapify(array, i, size, 0);
	}
}
