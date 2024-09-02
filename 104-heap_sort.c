#include "sort.h"


#define parentIndex(x) (((x) - 1) / 2)
#define leftChildIndex(x) (((x) * 2) + 1)


/**
 * swap - program that swaps two elements in an array and prints the array after swapping
 *
 * this function swaps two elements in an array;
 * it takes pointers to the elements to be swapped and performs the swap operation only if the elements are different;
 * after swapping, it prints the current state of the array for visualization;
 * the swap is done using a three-step arithmetic operation to avoid using a temporary variable
 *
 * @array: the array containing the elements to swap
 * @array_size: the size of the array, used for printing
 * @elem1_ptr: a pointer to the first element to be swapped
 * @elem2_ptr: a pointer to the second element to be swapped
 *
 * Return: nothing (void)
 */

void swap(int *array, size_t array_size, int *elem1_ptr, int *elem2_ptr)
{
	if (*elem1_ptr != *elem2_ptr)
	{
		*elem1_ptr = *elem1_ptr + *elem2_ptr;
		*elem2_ptr = *elem1_ptr - *elem2_ptr;
		*elem1_ptr = *elem1_ptr - *elem2_ptr;
	}
	print_array((const int *)array, array_size);
}



/**
 * siftDownInHeap - program that adjusts the heap structure from a specific node downwards to maintain the max-heap property
 *
 * this function adjusts a heap to maintain the max-heap property starting from a given node;
 * it compares parent nodes with their children and swaps them if the max-heap property is violated;
 * this sifting down is crucial for heap sort and is done iteratively until the heap is restored
 *
 * @array: the array representing the heap
 * @start_index: the index to start the sifting down process
 * @end_index: the index to end the sifting down process
 * @heap_size: the size of the heap
 *
 * Return: nothing (void)
 */

void siftDownInHeap(int *array, size_t start_index, size_t end_index, size_t heap_size)
{
	size_t root = start_index, swap_index, child_index;

	while (leftChildIndex(root) <= end_index)
	{
		child_index = leftChildIndex(root);
		swap_index = root;

		if (array[swap_index] < array[child_index])
			swap_index = child_index;

		if (child_index + 1 <= end_index && array[swap_index] < array[child_index + 1])
			swap_index = child_index + 1;

		if (swap_index == root)
			return;

		swap(array, heap_size, &array[root], &array[swap_index]);
		root = swap_index;
	}
}



/**
 * buildMaxHeap - program that converts an array into a max-heap
 *
 * this function transforms an array into a max-heap;
 * it starts from the lowest non-leaf nodes and applies the 'siftDownInHeap' function to each, moving upwards
 * to the root of the heap;
 * this process ensures that the array satisfies the max-heap property at every level
 *
 * @array: the array to be transformed into a max-heap
 * @array_size: the size of the array
 *
 * Return: nothing (void)
 */

void buildMaxHeap(int *array, size_t array_size)
{
	ssize_t start_index = 0;

	start_index = parentIndex(array_size - 1);

	while (start_index >= 0)
	{
		siftDownInHeap(array, start_index, array_size - 1, array_size);
		start_index--;
	}
}



/**
 * heapSort - program that sorts an array using the "Heap sort" algorithm in ascending order
 *
 * this function performs heap sort on an array;
 * it first builds a max-heap using 'buildMaxHeap' function;
 * then, it repeatedly swaps the maximum element (at the root) with the last element of the heap and decreases
 * the heap size by one, followed by a 'siftDownInHeap' to restore the max-heap property;
 * this process is repeated until the entire array is sorted
 *
 * we must implement the "sift-down" heap sort algorithm
 * we’re expected to print the array after each time we swap two elements
 *
 * @array: the array to be sorted
 * @array_size: the size of the array
 *
 * Return: nothing (void)
 */

void heapSort(int *array, size_t array_size)
{
	size_t end_index;

	if (!array || array_size < 2)
		return;

	buildMaxHeap(array, array_size);
	end_index = array_size - 1;

	while (end_index > 0)
	{
		swap(array, array_size, &array[end_index], &array[0]);
		end_index--;
		siftDownInHeap(array, 0, end_index, array_size);
	}
}
