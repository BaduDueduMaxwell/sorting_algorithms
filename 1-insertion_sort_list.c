#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers \
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insertion, *temp;

	if  (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insertion = i->prev;
		while (insertion != NULL && i->n < insertion->n)
		{
			swap_nodes(list, &insertion, i);
			print_list((const listint_t *)*list);
		}
	}
}
