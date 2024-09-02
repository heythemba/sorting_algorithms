#include "sort.h"

/**
 * print_array - program that prints the elements of an integer array
 *
 * this function iterates through each element of the array and prints it;
 * elements are separated by commas for better readability;
 * it ensures that no extra comma is printed at the end of the list;
 * it also handles the case where the array is NULL by not performing any action
 *
 * @array: a pointer to the first element of the array to be printed
 * @size: the number of elements in the array (it is of type 'size_t' to match the standard C size type)
 *
 * Return: nothing (void)
 */

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");

		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}