#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *		using Bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] += array[j + 1];
				array[j + 1] = array[j] - array[j + 1];
				array[j] -= array[j + 1];
			}
		}
	}
}
