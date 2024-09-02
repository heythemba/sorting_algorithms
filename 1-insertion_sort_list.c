#include "sort.h"

/**
 * swap_backward - program that swaps nodes in a doubly linked list in a backward direction
 *
 * this function iterates through the list in reverse order;
 * if the current node's value is less than its previous node's value, it swaps them;
 * it continues this process until the start of the list is reached or no swap is needed
 *
 * @current_node: a pointer to the current node in the list
 *
 * Return: nothing (void)
 */

void swap_backward(listint_t *current_node)
{
	listint_t *prev_prev_node, *list_head;

	while (current_node->prev != NULL)
	{
		if (current_node->n < current_node->prev->n)
		{
			prev_prev_node = current_node->prev->prev;
			current_node->prev->next = current_node->next;
			current_node->next = current_node->prev;
			current_node->prev->prev = current_node;
			current_node->prev = prev_prev_node;

			if (current_node->next->next != NULL)
				current_node->next->next->prev = current_node->next;

			if (prev_prev_node != NULL)
				prev_prev_node->next = current_node;

			/* Finding the new head of the list after swap */
			list_head = current_node;

			while (list_head->prev != NULL)
				list_head = list_head->prev;

			print_list(list_head);
		}
		else
			current_node = current_node->prev;
	}
}


/**
 * swap_forward - program that swaps nodes in a doubly linked list in a forward direction
 * and then calls swap_backward
 *
 * this function first swaps the current node with its next node if needed
 * (in case the current element is larger than its next element), and then
 * calls swap_backward to ensure proper ordering in reverse direction;
 * so it moves the element towards the end of the list to maintain sorting
 *
 * @current_node: a pointer to the current node in the list
 *
 * Return: nothing (void)
 */

void swap_forward(listint_t *current_node)
{
	listint_t *prev_node, *list_head;

	prev_node = current_node->prev;

	if (prev_node != NULL)
	{
		prev_node->next = current_node->next;
		current_node->next->prev = prev_node;
	}

	else
		current_node->next->prev = NULL;

	current_node->prev = current_node->next;

	if (current_node->next->next != NULL)
	{
		current_node->next = current_node->next->next;
		current_node->prev->next = current_node;
		current_node->next->prev = current_node;
	}

	else
	{
		current_node->next->next = current_node;
		current_node->next = NULL;
	}

	/* Finding the new head of the list after swap */
	list_head = current_node;

	while (list_head->prev != NULL)
		list_head = list_head->prev;

	print_list(list_head);

	swap_backward(current_node->prev);
}


/**
 * insertion_sort_list - program that performs an "Insertion sort" on a doubly linked list in ascending order
 *
 * this function iteratively traverses the list, comparing each node with its next node;
 * if a node's value is greater than its next, it swaps them to maintain order;
 * it continues this process until the entire list is sorted;
 *
 * we are not allowed to modify the integer n of a node:
 * we have to swap the nodes themselves;
 * we’re expected to print the list after each time we swap two elements
 *
 * @list_head: a pointer to the pointer of the head of the list
 *
 * Return: nothing (void)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;

	current_node = *list;

	while (current_node->next != NULL)
	{
		if (current_node->n > current_node->next->n)
		{
			swap_forward(current_node);
		}

		else
			current_node = current_node->next;
	}

	/* Resetting the list head to the beginning after sorting */
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}