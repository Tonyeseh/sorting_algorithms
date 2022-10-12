#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *			in ascending order using Insertion sort algorithm
 *
 * @list: pointer to the head of the list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *curr = (*list)->next, *next, *prev = NULL;

	while (curr)
	{
		next = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			prev = curr->prev;
			if (!prev->prev)
				*list = curr;
			tmp = curr->next;
			if (tmp)
				tmp->prev = prev;
			curr->next = prev;
			prev->next = tmp;
			tmp = prev->prev;
			prev->prev = curr;
			if (tmp)
				tmp->next = curr;
			curr->prev = tmp;
			print_array(array, size);
		}
		curr = next;
	}
}
