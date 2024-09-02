#include "sort.h"

/**
 * count_occurrences - program that counts the occurrences of a specific value within an array
 *
 * this function count how many times a particular integer ('target_value') appears within
 * a given array of integers ('array')
 *
 * @array: a pointer to the first element of the array of integers;
 *         this array contains the elements in which the function searches for the target value
 * @size: the number of elements in the array (the size of the array)
 * @target_value: the value to count within the array
 *
 * Return: the total number of occurrences of the target value in the array
 */

int count_occurrences(int *array, size_t size, int target_value)
{
	int occurrence_count = 0;
	size_t index;

	for (index = 0; index < size; index++)
	{
		if (array[index] == target_value)
			occurrence_count++;
	}
	return (occurrence_count);
}



/**
 * counting_sort - program that implements the "Counting sort" algorithm for sorting an array of integers
 * in ascending order
 *
 * this algorithm works best when the range of potential values in the array is not significantly larger
 * than the number of elements;
 *
 * the function operates in several steps:
 * 1. find the maximum value in the array to determine the range of counts
 * 2. allocate a count array with a size equal to the maximum value plus one, initialized to zero
 * 3. count the occurrence of each value in the original array and store these counts in the count array
 * 4. transform the count array to represent the cumulative count of elements, making it easier to place
 *    each element in its correct sorted position
 * 5. create a sorted array and populate it by placing each element from the original array into the correct
 *    position as indicated by the count array
 * 6. copy the sorted elements back into the original array
 *
 * this function uses dynamic memory allocation for the count array and the sorted array;
 * it is essential to free this memory to prevent leaks
 *
 * we can assume that array will contain only numbers >= 0;
 * we’re expected to print our counting array once it is set up;
 * this array is of size 'max_value' + 1 where 'max_value' is the largest number in array
 *
 * @array: the array to be sorted
 * @size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void counting_sort(int *array, size_t size)
{
	int max_value = 0, cumulative_count, range_value = 0;
	size_t index, count_index;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;

	/* Find the maximum value in the array */
	for (index = 0; index < size; index++)
	{
		if (array[index] > max_value)
		{
			max_value = array[index];
		}
	}

	/* Allocate memory for the count array */
	count_array = malloc(sizeof(int) * (max_value + 1));

	if (!count_array)
		return;

	/* Build the count array */
	for (count_index = 0; count_index < ((size_t)max_value + 1); count_index++)
	{
		if (count_index == 0)
			count_array[count_index] = count_occurrences(array, size, range_value);

		else
		{
			cumulative_count = count_array[count_index - 1] + count_occurrences(array, size, range_value);
			count_array[count_index] = cumulative_count;
		}
		range_value++;
	}
	print_array(count_array, (max_value + 1));

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * size);

	if (!sorted_array)
	{
		free(count_array);
		return;
	}

	/* Sort the array */
	for (index = 0; index < size; index++)
		sorted_array[count_array[array[index]]-- - 1] = array[index];

	/* Copy the sorted array back to the original array */
	for (index = 0; index < size; index++)
		array[index] = sorted_array[index];

	free(sorted_array);
	free(count_array);
}
