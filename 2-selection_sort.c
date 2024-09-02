#include "sort.h"

/**
 * swap_int_array_elements - program that swaps the values of two integers
 *
 * @first_ptr: a pointer to the first integer
 * @second_ptr: a pointer to the second integer
 *
 * Return: nothing (void)
 */

void swap_int_array_elements(int *first_ptr, int *second_ptr)
{
	int temp = *first_ptr;

	*first_ptr = *second_ptr;
	*second_ptr = temp;
}


/**
 * selection_sort - program that implements the "Selection sort" algorithm to sort
 * an array of integers in ascending order
 *
 * this algorithm repeatedly finds the minimum element from the unsorted part
 * and moves it to the beginning;
 *
 * it divides the input array into two parts: a sorted subarray which is built up
 * from left to right and remains at the beginning of the array, and a subarray of
 * remaining unsorted items that occupy the rest of the array;
 * initially, the sorted subarray is empty, while the unsorted subarray is the entire input array;
 *
 * the algorithm works by repeatedly selecting the smallest (or largest, depending on the sorting order)
 * element from the unsorted subarray, swapping it with the leftmost unsorted element (putting it in sorted order),
 * and moving the subarray boundaries one element to the right;
 *
 * we’re expected to print the array after each time we swap two elements
 *
 * @array: a pointer to the array of integers to be sorted
 * @size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void selection_sort(int *array, size_t size)
{
	size_t current_index, compare_index, min_index;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size; current_index++)
	{
		min_index = current_index;

		/* Find the minimum element in the unsorted part */
		for (compare_index = current_index + 1; compare_index < size; compare_index++)
		{
			if (array[compare_index] < array[min_index])
				min_index = compare_index;
		}

		/* Swap the found minimum element with the first element of the unsorted part */
		if (min_index != current_index)
		{
			swap_int_array_elements(&array[min_index], &array[current_index]);
			print_array(array, size);
		}
	}
}
