#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @list: pointer to the list head
 * @n1: first node
 * @n2: second node
 *
 * Return: Nothing
 */

void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *tmp;
	if (!n2->prev)
		*list = n1;
	tmp = n1->next;
	if (tmp)
		tmp->prev = n2;
	n1->next = n2;
	n2->next = tmp;
	tmp = n2->prev;
	n2->prev = n1;
	if (tmp)
		tmp->next = n1;
	n1->prev = tmp;
	print_list(*list);
}

void cocktail_sort_list(listint_t **list)
{
	int internal_swap, swap = 1;
	listint_t *current_node, *next_node, *previous_node, *top_sorted = NULL, *bottom_sorted = NULL;

	current_node = *list;
	while (swap)
	{
		swap = 0;
		while (current_node->next != top_sorted)
		{
			internal_swap = 0;
			next_node = current_node->next;
			if (current_node->n > next_node->n)
			{
				swap_nodes(list, next_node, current_node);
				internal_swap = swap = 1;
			}
			if (current_node->next == top_sorted)
			{
				top_sorted = current_node;
				current_node = current_node->prev;
				break;
			}
			if (!internal_swap)
				current_node = current_node->next;
		}
		if (!swap)
			break;
		swap = 0;
		while (current_node->prev != bottom_sorted)
		{
			internal_swap = 0;
			previous_node = current_node->prev;
			if (current_node->n < previous_node->n)
			{
				swap_nodes(list, current_node, previous_node);
				internal_swap = swap = 1;
			}
			if (current_node->prev == bottom_sorted)
			{
				bottom_sorted = current_node;
				current_node = current_node->next;
				break;
			}
			if (!internal_swap)
				current_node = current_node->prev;
		}
	}
}
