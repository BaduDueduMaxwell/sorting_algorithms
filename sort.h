#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/* Define the structure for anode in the doubly linked list */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* Function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);

#endif
