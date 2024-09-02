#include "sort.h"

/**
 * swap_listint_nodes - program that swaps two nodes in a doubly linked list
 *
 * this function reassigns pointers to ensure that the nodes are swapped in place
 * without disrupting the list's integrity
 *
 * @element1: the first node in the list to be swapped
 * @element2: the second node in the list to be swapped
 *
 * Return: nothing (void)
 */

void swap_listint_nodes(listint_t *element1, listint_t *element2)
{
	if (element1->prev)
	{
		element1->prev->next = element2;
	}

	if (element2->next)
	{
		element2->next->prev = element1;
	}

	element1->next = element2->next;
	element2->prev = element1->prev;
	element1->prev = element2;
	element2->next = element1;
}



/**
 * tail_traverse - program that performs a backward traversal from the tail of the list
 *
 * this function checks and swaps adjacent nodes if they are not in the desired order, iterating
 * until the head of the list is reached or no swaps are needed;
 * this function is particularly used in the "Cocktail sort" algorithm to handle the backward pass
 *
 * @list_head: the starting point for the traversal, usually the head of the list
 * @list_tail: the end point for the traversal, usually the tail of the list
 * @current_list: the current list being sorted;
 * 		  it is used for updating the list and for visualizing the sorting process
 *
 * Return: the updated head of the list after completing the backward traversal
 */

listint_t *tail_traverse(listint_t *list_head, listint_t *list_tail, listint_t *current_list)
{
	while (list_tail && list_tail->prev)
	{
		if (list_tail->n < list_tail->prev->n)
		{
			swap_listint_nodes(list_tail->prev, list_tail);

			if (list_tail->prev == NULL)
				current_list = list_tail;

			print_list(current_list);
		}
		else
			list_tail = list_tail->prev;

		if (list_tail->prev == NULL)
			list_head = list_tail;
	}
	return (list_head);
}



/**
 * cocktail_sort_list - program that implements the "Cocktail sort" algorithm on a doubly linked list
 * in ascending order
 *
 * this sorting algorithm is a variation of bubble sort;
 * it traverses the list forward and backward in alternate steps, swapping adjacent elements
 * if they are in the wrong order;
 * this process continues until no swaps are needed, indicating that the list is sorted;
 *
 * we are not allowed to modify the integer n of a node: we have to swap the nodes themselves;
 * we’re expected to print the list after each time we swap two elements
 *
 * @list: a pointer to the pointer of the head of the list to be sorted
 *
 * Return: nothing (void)
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current_tail, *current_head, *current_len;
	int length, round = 0, was_swapped;

	if (!list || !*list)
		return;

	current_len = *list;

	for (length = 0; current_len; length++)
	{
		current_len = current_len->next;
	}

	if (length < 2)
		return;

	current_head = *list;

	while (round < length)
	{
		was_swapped = 0;

		while (current_head && current_head->next)
		{
			if (current_head->n > current_head->next->n)
			{
				swap_listint_nodes(current_head, current_head->next);
				was_swapped++;
				if (current_head->prev->prev == NULL)
					*list = current_head->prev;

				print_list(*list);
			}

			else
				current_head = current_head->next;

			if (current_head->next == NULL)
				current_tail = current_head;
		}
		current_head = tail_traverse(current_head, current_tail, *list);
		*list = current_head;
		round++;
	}
}
