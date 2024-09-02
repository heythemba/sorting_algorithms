#include "sort.h"

/**
 * print_list - program that prints the elements of a doubly linked list
 *
 * this function traverses a doubly linked list and prints each element's value;
 * values are separated by commas for readability;
 * the function iterates through the list by following the 'next' pointers until the end of the list is reached;
 * it handles the formatting to ensure a clean, comma-separated list of values is printed to the standard output
 *
 * @list: a pointer to the head of the doubly linked list to be printed
 *
 * Return: nothing (void)
 */

void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}