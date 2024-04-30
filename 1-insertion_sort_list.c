#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
        listint_t *insertion_point = NULL;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; \
	     current = current->next)
	{
		insertion_point = current->prev;
		while (insertion_point != NULL && \
		       insertion_point->n > current->n)
		{
			insertion_point->next = current->next;
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = current;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;
			current->next = insertion_point;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			insertion_point = current->prev;
		}
	}
}