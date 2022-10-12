#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * an ascending order using the Selection sort algorithm.
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest, tmp;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[smallest] > array[j])
				smallest = j;
		}
		if (smallest != i)
		{
			tmp = array[smallest];
			array[smallest] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
