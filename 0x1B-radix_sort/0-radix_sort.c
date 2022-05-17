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

	for (i = 0; i < n; i++)
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
	int i, *count;

	output = malloc(sizeof(int) * n);
	count = malloc(sizeof(int) * getMax(arr, n) + 1);
	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
	}
	for (i = 0; i <= getMax(arr, n); i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i <= getMax(arr, n); i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
	free(count);
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
