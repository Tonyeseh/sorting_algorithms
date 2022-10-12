#include <stdlib.h>
#include "sort.h"

/**
 * max_element - finds the max element in an array
 *
 * @array: array
 * @size: size of array
 *
 * Returns: The largest number
 */

int max_element(int *array, size_t size)
{
	size_t i;
	int max_ele = array[0];
	for (i = 1; i < size; i++)
	{
		if (max_ele < array[i])
			max_ele = array[i];
	}
	return (max_ele);
}



/**
 * create_array - creates an array of arbituary size
 *
 * @size: size of array to be created
 *
 * Return: pointer to new array, if succeeds or NULL if failed
 */

int *create_array(size_t size)
{
	size_t i;
	int *new_array = NULL;
	if (size > 0)
	{
		new_array = malloc(sizeof(int) * size);
		for (i = 0; i < size; i++)
			new_array[i] = 0;
	}
	return (new_array);
}


/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *count, *new_array, max_elem, i;

	if (!array || size < 2)
		return;
	max_elem = max_element(array, size);
	count = create_array(max_elem + 1);
	new_array = create_array(size);
	if (!count || !new_array)
		return;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i < max_elem + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max_elem + 1);

	for (i = (int)size - 1; i >= 0; i--)
		new_array[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];

	free(new_array);
	free(count);
}
