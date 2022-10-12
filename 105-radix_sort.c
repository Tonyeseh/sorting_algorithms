#include <stdlib.h>
#include "sort.h"


/**
 * max_value_place - finds the max number and it's number of digits
 *
 * @array: array
 * @size: size of array
 *
 * Return: number of digits in the max value
 */
int max_value_place(int * array, size_t size)
{
	int digit_num = 0;
	size_t i = 1;
	int max = array[0];

	while (i < size)
	{
		if (max < array[i])
			max = array[i];
		i++;
	}

	while (max)
	{
		max /= 10;
		digit_num++;
	}
	return digit_num;
}


/**
 * get_rem - get number at a place value. The count starts from the LSD as 1
 *
 * @num: number
 * @place: place value
 *
 * Return: number at a place value
 */

int get_rem(int num, int place)
{
	int rem;
	while (place)
	{
		rem = num % 10;
		num /= 10;
		place--;
	}
	return rem;
}



/**
 * create_array - create a new int array of size size
 *
 * @size: size of array
 *
 * Return: pointer to an integer array or NULL if failed
 */
int *create_array(size_t size)
{
	int *array = malloc(sizeof(int) * size);
	if (array)
		return (array);
	else
		return NULL;
}



/**
 * radix_sort - sorts an array of integers in ascending order using the Radix sort algorithm.
 *
 *
 * Descriptions: Uses LSD radix sort algorithm
 *		array will contain only numbers >= 0
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void radix_sort(int *array, size_t size)
{
	int i, *count, *new_array, num_of_digit, place;

	place = 1;
	count = create_array(10);
	new_array = create_array(size);
	if (!count || !new_array)
		return;
	num_of_digit = max_value_place(array, size);
	while (place <= num_of_digit)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < (int)size; i++)
			count[get_rem(array[i], place)] += 1;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
			new_array[--count[get_rem(array[i], place)]] = array[i];

		for (i = 0; i < (int)size; i++)
			array[i] = new_array[i];
		place++;
		print_array(array, size);
	}
	free(new_array);
	free(count);
}
