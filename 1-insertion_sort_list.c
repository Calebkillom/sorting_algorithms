#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			temp = sorted->prev;
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;
			if (temp != NULL)
				temp->next = current;
			else
				*list = current;
			current->prev = temp;
			current->next = sorted;
			sorted->prev = current;
			sorted = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
