#include "sort.h"

/**
 * bubble_sort - program that performs bubble sort on an integer array in ascending order
 *
 * this function sorts an array of integers in ascending order using the "Bubble sort" algorithm;
 * it iterates through the array repeatedly, swapping adjacent elements if they are in the wrong order;
 * the process is repeated until the array is sorted;
 *
 * we’re expected to print the array after each time we swap two elements
 *
 * @array: an integer pointer to the array that will be sorted
 * @size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void bubble_sort(int *array, size_t size)
{
	int swapTemp; /* Temporary variable for swapping elements */
	size_t outerIndex, innerIndex;

	if (array == NULL || size == 0)
		return;

	for (outerIndex = 0; outerIndex < size; outerIndex++)
	{
		for (innerIndex = 0; innerIndex < size - 1; innerIndex++)
		{
			if (array[innerIndex] > array[innerIndex + 1])
			{
				/* Swapping elements */
				swapTemp = array[innerIndex];
				array[innerIndex] = array[innerIndex + 1];
				array[innerIndex + 1] = swapTemp;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
