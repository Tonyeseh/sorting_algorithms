#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * merge - merges arrays together in ascending order
 *
 * @array: array to be sorted
 * @low: sorting starts from here
 * @mid: middle of array to be sorted
 * @high: high of the array to be sorted
 *
 * Return: Nothing
 */
void merge(int *array, int low, int mid, int high)
{
	int i, j, k;
	int *new_array = malloc(sizeof(int) * (high - low + 1));
	if (!new_array)
		return;

	i = low;
	j = mid + 1;
	k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array((array + low), mid - low + 1);
	printf("[right]: ");
	print_array((array + mid + 1), high - mid);
	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
			new_array[k++] = array[i++];
		else
			new_array[k++] = array[j++];
	}
	for (; i <= mid;)
		new_array[k++] = array[i++];
	for (; j <= high;)
		new_array[k++] = array[j++];

	printf("[Done]: ");
	print_array(new_array, high - low + 1);
	for (k = 0; k < high - low + 1; k++)
		array[low + k] = new_array[k];

	free(new_array);
}


/**
 * split_and_merge - splits the array recursively and call merge
 *
 * @array: array to be sorted
 * @low: lowest index of the array to be sorted
 * @high: highest index of the array
 *
 * Return: Nothing
 */
void split_and_merge(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		printf("mid - %d\n", mid);
		split_and_merge(array, low, mid - 1);
		split_and_merge(array, mid, high);
		merge(array, low, mid, high);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using the Merge sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	split_and_merge(array, 0, size - 1);
}
