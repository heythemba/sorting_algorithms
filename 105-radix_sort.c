#include "sort.h"

/**
 * extract_digit - program that extracts a specific digit from a given number based on its position
 *
 * this function calculates the appropriate power of 10 to isolate the desired digit
 * and then uses modulo operation to extract it;
 * the digit index starts from 0 (rightmost digit) and increases towards the left;
 * for example, in the number 12345, the 0th digit is 5, and the 2nd digit is 3
 *
 * @number: the long integer number from which the digit will be extracted
 * @digit_index: the position of the digit to be extracted, starting from 0
 *
 * Return: the integer value of the extracted digit
 */

int extract_digit(long number, int digit_index)
{
	long pow_ten = 1L;
	long extracted_digit;
	int i;

	for (i = 0; i < digit_index; i++)
		pow_ten *= 10L;

	extracted_digit = ((number / pow_ten) % 10);

	return (extracted_digit);
}



/**
 * single_radix_pass - program that performs a single pass of the radix sort based on a specific digit
 *
 * this function sorts the elements of the original array into a new array based on the value of
 * the specified digit;
 *
 * it uses a "counting sort" technique for this purpose:
 * - it first counts the occurrences of each digit in the specified position using a 'buckets' array;
 * - it then uses this information to place each element from the original array into the correct position
 *   in the sorted array;
 *
 * @original_array: the array of integers to be sorted
 * @array_size: the number of elements in the array
 * @digit_index: the digit index to sort by (0 for least significant digit)
 * @sorted_array: a buffer array to hold the sorted output of this pass
 *
 * Return: 1 to indicate successful completion
 */

int single_radix_pass(int *original_array, ssize_t array_size, int digit_index, int *sorted_array)
{
	ssize_t i = 0;

	int count_buckets[10] = {0};

	for (i = 0; i < array_size; i++)
		count_buckets[extract_digit(original_array[i], digit_index)]++;

	for (i = 1; i <= 9; i++)
		count_buckets[i] += count_buckets[i - 1];

	for (i = array_size - 1; i > -1; i--)
		sorted_array[--count_buckets[extract_digit(original_array[i], digit_index)]] = original_array[i];

	return (1);
}



/**
 * radix_sort - program that sorts an array of integers using the "Radix sort" algorithm
 *
 * "Radix sort" is a non-comparative sorting algorithm;
 * it sorts numbers by processing individual digits;
 * numbers are sorted based on their least significant digit first, then the next least significant, and so on;
 *
 * this function first identifies the number of significant digits in the largest number in the array;
 * it then performs a radix sort pass for each digit;
 * after sorting based on each digit, the array becomes fully sorted;
 * the function dynamically allocates memory for the intermediate sorting process
 *
 * we must implement the "LSD" radix sort algorithm
 * we can assume that array will contain only numbers >= 0
 * we’re expected to print the array each time we increase our significant digit
 *
 * @array: the array of integers to be sorted
 * @array_size: the size (number of elements) of the array
 *
 * Return: nothing (void)
 */

void radix_sort(int *array, size_t array_size)
{
	int *current_array, *temp_array, *swap_ptr, max_value = 0;
	size_t i, significant_digits = 1;

	if (!array || array_size < 2)
		return;

	/* Find the maximum value to determine the number of significant digits */
	for (i = 0; i < array_size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	while (max_value /= 10)
		significant_digits++;

	current_array = array;
	temp_array = malloc(sizeof(int) * array_size);

	if (!temp_array)
		return;

	for (i = 0; i < significant_digits; i++)
	{
		single_radix_pass(current_array, (ssize_t)array_size, i, temp_array);
		swap_ptr = current_array;
		current_array = temp_array;
		temp_array = swap_ptr;
		print_array(current_array, array_size);
	}

	for (i = 0; i < array_size; i++)
		array[i] = current_array[i];

	free(temp_array);
}
