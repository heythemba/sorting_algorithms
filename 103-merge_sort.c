#include "sort.h"

/**
 * merge_halves - program that merges two sorted halves of an array into a single sorted array
 *
 * this function is a part of the "Merge sort" algorithm, responsible for the merging step, where
 * the two halves [start_index, mid) and [mid, end_index) should be sorted;
 * 'mid' is calculated as the midpoint between 'start_index' and 'end_index'
 *
 * @original_array: the original array that contains the two halves to be merged
 * @start_index: the starting index of the first half in the original array
 * @end_index: the ending index of the second half in the original array
 * @merged_array: the array where the merged result will be stored
 *
 * Return: nothing (void)
 */

void merge_halves(int *original_array, size_t start_index, size_t end_index, int *merged_array)
{
	size_t left_index = start_index, right_index, left_half_end;
	size_t k, mid = (start_index + end_index) / 2;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(original_array + start_index, mid - start_index);
	printf("[right]: ");
	print_array(original_array + mid, end_index - mid);

	right_index = mid;

	for (k = start_index; k < end_index; k++)
	{
		left_half_end = mid;

		if (left_index < left_half_end && (right_index >= end_index || original_array[left_index] <= original_array[right_index]))
		{
			merged_array[k] = original_array[left_index++];
		}

		else
		{
			merged_array[k] = original_array[right_index++];
		}
	}

	printf("[Done]: ");

	print_array(merged_array + start_index, end_index - start_index);
}



/**
 * recursive_merge_sort - program that recursively sorts an array using the "top-down" merge sort approach
 *
 * this function divides the array into smaller subarrays, sorts them, and then merges them;
 * it splits the array into two halves, recursively sorts each half, and then merges them using the 'merge_halves' function;
 * this approach involves dividing the problem into smaller, more manageable subproblems, solving each recursively,
 * and combining their results
 *
 * @array_to_sort: the array to be sorted
 * @start_index: the starting index of the subarray to be sorted
 * @end_index: the ending index of the subarray to be sorted
 * @temp_array: a temporary array used for the sorting and merging process:
 *              it stores intermediate sorting results and acts as a buffer during merging
 *
 * Return: nothing (void)
 */

void recursive_merge_sort(int *array_to_sort, size_t start_index, size_t end_index, int *temp_array)
{
	size_t mid = (start_index + end_index) / 2;

	if (end_index - start_index < 2)
	{
		return; /* Base case: if the subarray has less than two elements, return */
	}

	/* Recursively sort the first and second halves */
	recursive_merge_sort(temp_array, start_index, mid, array_to_sort);
	recursive_merge_sort(temp_array, mid, end_index, array_to_sort);

	/* Merge the sorted halves */
	merge_halves(temp_array, start_index, end_index, array_to_sort);
}



/**
 * merge_sort_array - program that implements the "Merge sort" algorithm to sort an array of integers in ascending order
 *
 * this function is an entry point for the recursive merge sort algorithm;
 * it allocates a temporary array which is used throughout the sorting process for storing and merging sorted segments,
 * and uses the top-down approach for merge sort
 *
 * "Merge sort" is a divide-and-conquer algorithm that divides the array into halves, sorts each half, and then merges them
 *
 * we must implement the "top-down" merge sort algorithm:
 * - when we divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array:
 *   {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
 * - we sort the left array before the right array
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing (void)
 */

void merge_sort_array(int *array, size_t size)
{
	int *temp_array;
	size_t i;

	if (!array || size < 2)
		return; /* Check for an empty or single-element array */

	/* Allocate memory for the temporary array */
	temp_array = malloc(sizeof(int) * size);

	if (!temp_array)
		return;

	/* Copy elements from the original array to the temporary array */
	for (i = 0; i < size; i++)
		temp_array[i] = array[i];

	/* Perform the top-down merge sort */
	recursive_merge_sort(array, 0, size, temp_array);

	/* Free the temporary array */
	free(temp_array);
}
