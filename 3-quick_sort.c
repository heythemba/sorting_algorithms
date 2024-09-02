#include "sort.h"

/**
 * swap_partition_elements - program that swaps the values of two integers
 *
 * @first_ptr: a pointer to the first integer
 * @second_ptr: a pointer to the second integer
 *
 * Return: nothing (void)
 */

void swap_partition_elements(int *first_ptr, int *second_ptr)
{
	int temp = *first_ptr;

	*first_ptr = *second_ptr;
	*second_ptr = temp;
}



/**
 * partition - program that partitions the given segment of the array for the "Quicksort" algorithm
 *
 * this function selects a 'pivot' element from the array and partitions the other elements
 * into two sub-arrays, according to whether they are less than or greater than the pivot;
 * the pivot element itself is then placed in its correct position in the sorted array;
 * this is a key process in the quicksort algorithm
 *
 * @arr: the array to be sorted
 * @low: the starting index of the segment of the array to be partitioned
 * @high: the ending index of the segment of the array to be partitioned
 * @arraySize: the total size of the array, used for printing the array if needed
 *
 * Return: the index of the pivot element after partitioning
 */

int partition(int arr[], int low, int high, size_t arraySize)
{
	int pivotElement = arr[high];
	int smallerElementIndex = (low - 1);
	int current;

	for (current = low; current < high; current++)
	{
		if (arr[current] <= pivotElement)
		{
			smallerElementIndex++;
			swap_partition_elements(&arr[smallerElementIndex], &arr[current]);

			if (current != smallerElementIndex)
				print_array(arr, arraySize);
		}
	}

	swap_partition_elements(&arr[smallerElementIndex + 1], &arr[high]);

	if (high != (smallerElementIndex + 1))
		print_array(arr, arraySize);

	return (smallerElementIndex + 1);
}



/**
 * performQuickSort - program that performs the "Quicksort" algorithm on a segment of an array recursively
 *
 * "Quicksort" is a highly efficient sorting algorithm and is based on partitioning of array of data
 * into smaller arrays;
 * a large array is partitioned into two arrays one of which holds values smaller than the specified value,
 * say pivot, based on which the partition is made and another array holds values greater than the pivot value;
 *
 * we must implement the "Lomuto partition" scheme;
 * the pivot should always be the last element of the partition being sorted;
 * we’re expected to print the array after each time we swap two elements
 *
 * @arr: the array to be sorted
 * @low: the starting index of the segment of the array to be sorted
 * @high: the ending index of the segment of the array to be sorted
 * @arraySize: the total size of the array, used for printing the array if needed
 *
 * Return: nothing (void)
 */

void performQuickSort(int arr[], int low, int high, size_t arraySize)
{
	int pivotIndex;

	if (low < high)
	{
		pivotIndex = partition(arr, low, high, arraySize);

		performQuickSort(arr, low, pivotIndex - 1, arraySize);
		performQuickSort(arr, pivotIndex + 1, high, arraySize);
	}
}



/**
 * quick_sort - program that initiates the "Quicksort" algorithm in ascending order
 *
 * this function is the entry point for the quicksort routine and it calls the 'performQuickSort' function
 * to sort the array;
 * it handles the case where the array is null or has zero elements, in which case it does nothing
 *
 * @arr: a pointer to the array of integers to be sorted
 * @arraySize: the size of the array to be sorted
 *
 * Return: nothing (void)
 */

void quick_sort(int *array, size_t arraySize)
{
	if (array == NULL || arraySize == 0)
		return;

	performQuickSort(arr, 0, (arraySize - 1), arraySize);
}