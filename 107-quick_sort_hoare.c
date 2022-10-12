#include <stddef.h>


/**
 * sort - main function that sorts
 *
 * @array: array to be sorted
 * @start_idx: start_idx
 * @end_idx: end_idx
 * @size: size of the array
 *
 * Return: Nothing
 */

void sort(int *array, int start_idx, int end_idx, size_t size)
{
	if (start_idx < end_idx)
	{
		int tmp;
		int pivot = end_idx;
		int cmp = start_idx;

		while (pivot != cmp)
		{
			if (array[pivot] > array[cmp] && pivot < cmp)
			{
				tmp = array[pivot];
				array[pivot] = array[cmp];
				array[cmp] = tmp;
				print_array(array, size);

				tmp = pivot;
				pivot = cmp;
				cmp = tmp;
			}
			else if (array[pivot] < array[cmp] && pivot > cmp)
			{
				tmp = array[pivot];
				array[pivot] = array[cmp];
				array[cmp] = tmp;
				print_array(array, size);

				tmp = pivot;
				pivot = cmp;
				cmp = tmp;
			}
			if (pivot < cmp)
				cmp -= 1;
			else if (pivot > cmp)
				cmp += 1;
		}

		sort(array, start_idx, pivot - 1, size);
		sort(array, pivot + 1, end_idx, size);
	}
}


/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *			using quick sort algorithm
 *
 * Description: Uses the Hoarse partition scheme
 *		Pivot is always the last element of the partition being sorted
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		sort(array, 0, size - 1, size);
}
