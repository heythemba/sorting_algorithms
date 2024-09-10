#include "sort.h"

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 *
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 *
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
	if (array[j] < pivot)
		{
		i++;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		if (i != j)
		print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the Quick Sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: (no retun)
 *
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int pi = lomuto_partition(array, low, high, size);

	quicksort(array, low, pi - 1, size);
	quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: (no return)
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quicksort(array, 0, size - 1, size);
}
