#include "sort.h"

/**
 * cocktail_sort_list - Sort doubly linked list of integers in ascending order
 *                      using Cocktail Shaker Sort algorithm.
 *
 * @list: Double pointer to the head of the list
 *
 * Return: (no return)
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = NULL;

	if (list == NULL || *list == NULL)
	return;

	while (swapped)
	{
	swapped = 0;
	current = *list;

	while (current->next != NULL)
		{
		if (current->n > current->next->n)
			{
			swap_nodes(current, current->next, list);
			swapped = 1;
			print_list(*list);
			}
		else
		current = current->next;
		}

	if (!swapped)
	break;

	swapped = 0;
	while (current->prev != NULL)
		{
		if (current->n < current->prev->n)
			{
			swap_nodes(current->prev, current, list);
			swapped = 1;
			print_list(*list);
			}
		else
		current = current->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 * @list: Double pointer to the head of the list
 *
 * Return: (no return)
 *
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp_prev, *temp_next;

	if (node1->prev != NULL)
	node1->prev->next = node2;
	else
	*list = node2;

	if (node2->next != NULL)
	node2->next->prev = node1;
	temp_prev = node1->prev;
	temp_next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = temp_prev;
	node1->next = temp_next;
}
