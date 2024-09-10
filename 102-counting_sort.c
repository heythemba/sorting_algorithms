#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: (no return)
 *
 */
void counting_sort(int *array, size_t size)
{
	int max_value;
	int *counting_array;
	int *output_array;
	size_t i;
	ssize_t j;

	if (array == NULL || size < 2)
	return;

	max_value = array[0];
	for (i = 1; i < size; i++)
	{
	if (array[i] > max_value)
	max_value = array[i];
	}
	counting_array = malloc(sizeof(int) * (max_value + 1));
	if (counting_array == NULL)
	return;
	for (i = 0; i <= (size_t)max_value; i++)
	counting_array[i] = 0;
	for (i = 0; i < size; i++)
	counting_array[(size_t)array[i]]++;
	for (i = 1; i <= (size_t)max_value; i++)
	counting_array[i] += counting_array[i - 1];
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
	free(counting_array);
	return;
	}
	for (j = (ssize_t)size - 1; j >= 0; j--)
	{
	output_array[counting_array[(size_t)array[j]] - 1] = array[j];
	counting_array[(size_t)array[j]]--;
	}
	for (i = 0; i < size; i++)
	array[i] = output_array[i];
	print_array(counting_array, (size_t)(max_value + 1));
	free(counting_array);
	free(output_array);
}
