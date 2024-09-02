#include "sort.h"

/**
 * swap - program that performs an in-place swap of two integers using arithmetic operations
 *
 * this function swaps the values of two different integers without using extra space (additional memory);
 * it cleverly uses arithmetic operations to exchange the values of the two integers;
 * it ensures that no extra memory allocation is required, making the swapping efficient
 *
 * @num1: a pointer to the first integer to be swapped
 * @num2: a pointer to the second integer to be swapped
 *
 * Return: nothing (void)
 */

void swap(int *num1, int *num2)
{
	if (*num1 != *num2)
	{
		*num1 = *num1 + *num2;
		*num2 = *num1 - *num2;
		*num1 = *num1 - *num2;
	}
}



/**
 * compare_and_swap_bitonic - program that compares and swaps adjacent elements in a "bitonic" sequence
 * to either ascend or descend
 *
 * this function is a core part of the "Bitonic sort" algorithm, ensuring that each half of the array forms
 * a bitonic sequence (this function is a parallel algorithm for sorting);
 * it compares and swaps elements to ensure each segment of the array is in either ascending or descending order;
 *
 * the function operates on a segment of the array defined by 'start_index' and 'end_index';
 * the bitonic property of the array segment is essential for the correctness of this function
 *
 * @ascending_order: a flag indicating the sorting order; 1 for ascending order, 0 for descending order
 * @array: a pointer to the array containing the bitonic sequence
 * @start_index: the starting index of the sequence within the array to be processed
 * @end_index: the ending index (exclusive) of the sequence within the array (not included in the processing)
 *
 * Return: nothing (void)
 */


void compare_and_swap_bitonic(int ascending_order, int *array, size_t start_index, size_t end_index)
{
	size_t half = (end_index - start_index + 1) / 2;
	size_t i;

	for (i = start_index; i < start_index + half; i++)
	{
		if ((array[i] > array[i + half]) == ascending_order)
			swap(&array[i], &array[i + half]);
	}
}



/**
 * merge_bitonic_sequence - program that merges segments of a "bitonic" sequence into a fully sorted sequence
 * in either ascending or descending order
 *
 * this recursive function divides the bitonic sequence into smaller segments and sorts each;
 * it is essential for converting the bitonic sequence into a monotonically increasing or decreasing sequence;
 * it uses divide and conquer approach, splitting the array segment into halves, and recursively sorting
 * each half in the desired order
 *
 * @ascending_order: a flag indicating the sorting order --> 1 for ascending, 0 for descending
 * @array: the array containing the bitonic sequence to be merged
 * @start_index: the starting index of the sequence within the array for the merging process
 * @end_index: the ending index of the sequence within the array for the merging process
 *
 * Return: nothing (void)
 */

void merge_bitonic_sequence(int ascending_order, int *array, size_t start_index, size_t end_index)
{
	size_t mid;

	if (end_index - start_index < 1)
		return;

	mid = (start_index + end_index) / 2;

	compare_and_swap_bitonic(ascending_order, array, start_index, end_index);

	merge_bitonic_sequence(ascending_order, array, start_index, mid);
	merge_bitonic_sequence(ascending_order, array, mid + 1, end_index);
}



/**
 * recursive_bitonic_sort - program that recursively sorts a segment of the array using the "Bitonic sort" algorithm
 *
 * this function divides the array into smaller bitonic sequences, sorts them, and then merges them
 * into a fully sorted array;
 * it combines recursive division of the array with bitonic merging to achieve sorting;
 * it is suitable for parallel processing due to its divide and conquer nature;
 *
 * we can assume that size will be equal to 2^k, where k >= 0 (when array is not NULL …);
 * we’re expected to print the array each time we swap two elements
 *
 * @ascending_order: a flag indicating the initial sorting order --> 1 for ascending, 0 for descending
 * @array: a pointer to the array segment to be sorted
 * @array_size: the total size of the array
 * @start_index: the starting index of the segment in the array to be sorted
 * @end_index: the ending index of the segment in the array to be sorted
 *
 * Return: nothing (void)
 */

void recursive_bitonic_sort(int ascending_order, int *array, size_t array_size, size_t start_index, size_t end_index)
{
	size_t mid;

	if (end_index - start_index < 1)
		return;

	mid = (start_index + end_index) / 2;

	printf("Merging [%zu/%zu] (%s):\n", end_index - start_index + 1, array_size, ascending_order ? "UP" : "DOWN");

	print_array(array + start_index, end_index - start_index + 1);

	recursive_bitonic_sort(1, array, array_size, start_index, mid);
	recursive_bitonic_sort(0, array, array_size, mid + 1, end_index);

	merge_bitonic_sequence(ascending_order, array, start_index, end_index);

	printf("Result [%zu/%zu] (%s):\n", end_index - start_index + 1, array_size, ascending_order ? "UP" : "DOWN");

	print_array(array + start_index, end_index - start_index + 1);

}



/**
 * bitonic_sort - program that sorts an array using the "Bitonic sort" algorithm
 *
 * this function initializes the recursive bitonic sorting process for the entire array;
 * it calls the 'recursive_bitonic_sort' function to perform the actual sorting;
 * it is designed to handle the entire array, making it the entry point for the bitonic sorting algorithm
 *
 * @array: a pointer to the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing (void)
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_bitonic_sort(1, array, array_size, 0, array_size - 1);
}
