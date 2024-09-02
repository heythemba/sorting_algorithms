#include "sort.h"

/**
 * calculate_optimal_gap - program that calculates the initial gap for "Shell sort" algorithm,
 * based on the size of the array
 *
 * this function determines the starting gap using the "Knuth sequence", which is
 * an effective increment sequence for Shell sort;
 * the Knuth sequence is generated using the formula: gap = gap * 3 + 1;
 * the sequence provides a series of progressively smaller gaps, allowing elements
 * to be moved into their correct position more efficiently than a simple adjacent swap
 *
 * @array_size: the size of the array to be sorted
 *
 * Return: the largest gap value calculated based on the Knuth sequence that is smaller than the array size
 */

size_t calculate_optimal_gap(size_t array_size)
{
	size_t gap = 1;

	while (gap < array_size)
	{
		gap = gap * 3 + 1;
	}

	return ((gap - 1) / 3);
}


/**
 * shell_sort - program that performs the "Shell sort" algorithm on an array in ascending order
 *
 * Shell sort is an advanced variant of the insertion sort that reduces the
 * movement of elements across long distances;
 * the algorithm works by comparing and swapping elements that are distant from each other,
 * rather than adjacent, effectively reducing the total number of movements;
 * this function initially sorts elements far apart from each other and progressively reduces
 * the gap between the elements to be compared;
 * the final stage of the algorithm is a simple insertion sort, but by this time, most elements
 * are already sorted, making the process faster;
 * the function iterates over the array, gradually reducing the gap and sorting the elements until
 * the entire array is sorted
 *
 * we must use the following sequence of intervals (the "Knuth sequence"):
 * n+1 = n * 3 + 1  -->  1, 4, 13, 40, 121, ...;
 * we’re expected to print the array each time we decrease the interval
 *
 * @array: a pointer to the array that needs to be sorted
 * @array_size: the size of the array
 *
 * Return: nothing (void)
 */

void shell_sort(int *array, size_t array_size)
{
	size_t gap, current_index, compare_index;
	int current_value;

	if (!array || array_size == 0)
		return;

	for (gap = calculate_optimal_gap(array_size); gap > 0; gap = (gap - 1) / 3)
	{
		for (current_index = gap; current_index < array_size; current_index++)
		{
			current_value = array[current_index];

			for (compare_index = current_index; compare_index > gap - 1 && array[compare_index - gap] > current_value; compare_index -= gap)
			{
				array[compare_index] = array[compare_index - gap];
			}

			array[compare_index] = current_value;
		}

		print_array(array, array_size);
	}
}
