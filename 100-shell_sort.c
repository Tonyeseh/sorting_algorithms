#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 *		Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	int j, i = 1, gap = 1;

	/* finding gap */
	while (gap < (int)(size / 3))
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (i = 0; (gap + i) < (int)size; i++)
		{
			if (array[gap + i] < array[i])
			{
				tmp = array[i];
				array[i] = array[gap + i];
				array[gap + i] = tmp;

				for (j = i; (j - gap) >= 0; j -= gap)
				{
					if (array[j] < array[j - gap])
					{
						tmp = array[j];
						array[j] = array[j - gap];
						array[j - gap] = tmp;
					}
					else
						break;
				}
			}
		}
		/* add print_array(array, size) after the gap line*/
		gap = gap / 3;
		print_array(array, size);
	}
}
