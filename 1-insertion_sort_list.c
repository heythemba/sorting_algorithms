#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm
 *
 * @list: Pointer to a pointer to the head of the linked list
 *
 * Return: (no return)
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	current = (*list)->next;

	while (current != NULL)
	{
	next = current->next;

	while (current->prev != NULL && current->n < current->prev->n)
		{
		prev = current->prev;
		prev->next = current->next;
		if (current->next != NULL)
		current->next->prev = prev;
		current->next = prev;
		current->prev = prev->prev;
		prev->prev = current;

		if (current->prev == NULL)
		*list = current;
		else
		current->prev->next = current;
		print_list(*list);
		}
	current = next;
	}
}
