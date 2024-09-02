#include "sort.h"

/**
 * swap_quick_sort_elements - program that swaps two elements in an array using arithmetic operations
 * to avoid using a temporary variable
 *
 * this function swaps two elements in an array without using a temporary variable;
 * it employs arithmetic operations for swapping;
 * after the swap operation, it prints the current state of the array;
 *
 * the elements pointed to by 'element_a' and 'element_b' are directly modified
 *
 * @array_to_sort: the array in which the swap is to be performed.
 * @array_size: the total number of elements in the array (size of the array), used for printing the array
 * @element_a: a pointer to the first element to be swapped.
 * @element_b: a pointer to the second element to be swapped.
 *
 * Return: nothing (void)
 */

void swap_quick_sort_elements(int *array_to_sort, size_t array_size, int *element_a, int *element_b)
{
	if (*element_a != *element_b)
	{
		*element_a = *element_a + *element_b;
		*element_b = *element_a - *element_b;
		*element_a = *element_a - *element_b;
	}
	print_array((const int *)array_to_sort, array_size);
}



/**
 * hoare_partition - program that partitions an array using the "Hoare partition scheme" for "Quicksort" algorithm
 *
 * this scheme selects a pivot and rearranges the elements of the array such that all elements smaller
 * than the pivot come before it, and all elements greater elements come after it;
 * the function returns the index at which the partition divides the array
 *
 * @partition_array: the array segment to partition
 * @array_size: the total number of elements in the array (size of the array)
 * @low_index: the starting index for the partitioning segment
 * @high_index: the ending index for the partitioning segment
 *
 * Return: the index position where the partition is divided
 */

size_t hoare_partition(int *partition_array, ssize_t array_size, ssize_t low_index, ssize_t high_index)
{
	size_t left_index = low_index - 1, right_index = high_index + 1;
	int pivot = partition_array[high_index];

	while (left_index < array_size)
	{
		while (partition_array[++left_index] < pivot)
			;
		while (partition_array[--right_index] > pivot)
			;
		if (left_index < right_index)
			swap_quick_sort_elements(partition_array, array_size,
						 &partition_array[left_index],
						 &partition_array[right_index]);

		else if (left_index >= right_index)
			break;
	}
	return (left_index);
}



/**
 * quicksort - program that recursively sorts an array segment using the "Quicksort" algorithm
 *
 * "Quicksort" is a divide-and-conquer algorithm that works by selecting a 'pivot' element and partitioning the array
 * around the pivot;
 * it first partitions the array and then recursively applies the same logic to the subarrays;
 * this function is called for each sub-segment of the array until the entire array is sorted
 *
 * @quicksort_array: the array to sort
 * @array_size: the total number of elements in the array
 * @low_index: the starting index of the segment to be sorted
 * @high_index: the ending index of the segment to be sorted
 *
 * Return: nothing (void)
 */

void quicksort(int *quicksort_array, size_t array_size, ssize_t low_index, ssize_t high_index)
{
	if (low_index < high_index)
	{
		size_t partition_index = hoare_partition(quicksort_array, array_size, low_index, high_index);
		quicksort(quicksort_array, array_size, low_index, partition_index - 1);
		quicksort(quicksort_array, array_size, partition_index, high_index);
	}
}



/**
 * quick_sort_hoare - program that initiates the Hoare version of the quicksort algorithm on an entire array
 *
 * "Quick sort" is a highly efficient sorting algorithm that employs a divide-and-conquer strategy;
 * this function serves as the entry point for the quicksort process;
 * it calls the 'quicksort' function to sort the array;
 * the sorting process involves selecting a 'pivot' element and then reordering the array so that all elements
 * with values less than the pivot come before it, while all elements with values greater than the pivot come after it;
 * this process is recursively applied to the sub-arrays formed from dividing the array at the pivot;
 * the efficiency of quicksort lies in its ability to sort large datasets rapidly with a time complexity of O(n log n)
 * on average;
 * the function does not return any value, but it modifies the array passed to it in place, resulting in a sorted array;
 * sorting is performed only if the array size is greater than 1;
 *
 * we must implement the "Hoare partition" scheme;
 * the pivot should always be the last element of the partition being sorted;
 * we’re expected to print the array after each time we swap two elements
 *
 * @array_to_sort: a pointer to the array that needs to be sorted
 * @array_size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void quick_sort_hoare(int *array_to_sort, size_t array_size)
{
	if (!array_to_sort || array_size < 2)
		return;

	quicksort(array_to_sort, array_size, 0, array_size - 1);
}
