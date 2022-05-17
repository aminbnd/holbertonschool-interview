#include "sort.h"

/**
 * getMax - Get the Max object
 *
 * @arr: array to sort
 * @n: integer
 * Return: int
 */

int getMax(int arr[], int n)
{
	int max = arr[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * countSort -  Funtiion
 *
 * @arr: array of int
 * @n: int
 * @exp: intp
 */

void countSort(int arr[], int n, int exp)
{
	int *output;
	int i, count[10] = {0};

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		free(output);

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}


/**
 * radix_sort - Radix sort
 *
 * @array: Array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int m = getMax(array, size);
	int exp;

	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
