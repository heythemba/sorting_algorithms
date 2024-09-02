#ifndef SORT_H
#define SORT_H


#include <stdlib.h>
#include <stdio.h>


/**
 * struct listint_s - structure representing a node in a doubly linked list
 *
 * @n: an integer value stored in the node
 * @prev: a pointer to the previous node in the doubly linked list (if this is the first node, it will be NULL)
 * @next: a pointer to the next node in the doubly linked list (if this is the last node, it will be NULL)
 */

typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;



/* functions provided */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* task 0 */
void bubble_sort(int *array, size_t size);

/* task 1 */
void swap_backward(listint_t *current_node);
void swap_forward(listint_t *current_node);
void insertion_sort_list(listint_t **list);

/* task 2 */
void swap_int_array_elements(int *first_ptr, int *second_ptr);
void selection_sort(int *array, size_t size);

/* task 3 */
void swap_partition_elements(int *first_ptr, int *second_ptr);
int partition(int arr[], int low, int high, size_t arraySize);
void performQuickSort(int arr[], int low, int high, size_t arraySize);
void quick_sort(int *array, size_t arraySize);


/* Advanced tasks */

/* task 100 */
size_t calculate_optimal_gap(size_t array_size);
void shell_sort(int *array, size_t array_size);

/* task 101 */
void swap_listint_nodes(listint_t *element1, listint_t *element2);
listint_t *tail_traverse(listint_t *list_head, listint_t *list_tail, listint_t *current_list);
void cocktail_sort_list(listint_t **list);

/* task 102 */
int count_occurrences(int *array, size_t size, int target_value);
void counting_sort(int *array, size_t size);

/* task 103 */
void merge_halves(int *original_array, size_t start_index, size_t end_index, int *merged_array);
void recursive_merge_sort(int *array_to_sort, size_t start_index, size_t end_index, int *temp_array);
void merge_sort_array(int *array, size_t size);

/* task 104 */
void swap(int *array, size_t array_size, int *elem1_ptr, int *elem2_ptr);
void siftDownInHeap(int *array, size_t start_index, size_t end_index, size_t heap_size);
void buildMaxHeap(int *array, size_t array_size);
void heapSort(int *array, size_t array_size);

/* task 105 */
int extract_digit(long number, int digit_index);
int single_radix_pass(int *original_array, ssize_t array_size, int digit_index, int *sorted_array);
void radix_sort(int *array, size_t array_size);

/* task 106 */
void swap(int *num1, int *num2);
void compare_and_swap_bitonic(int ascending_order, int *array, size_t start_index, size_t end_index);
void merge_bitonic_sequence(int ascending_order, int *array, size_t start_index, size_t end_index);
void recursive_bitonic_sort(int ascending_order, int *array, size_t array_size, size_t start_index, size_t end_index);
void bitonic_sort(int *array, size_t size);

/* task 107 */
void swap_quick_sort_elements(int *array_to_sort, size_t array_size, int *element_a, int *element_b);
size_t hoare_partition(int *partition_array, ssize_t array_size, ssize_t low_index, ssize_t high_index);
void quicksort(int *quicksort_array, size_t array_size, ssize_t low_index, ssize_t high_index);
void quick_sort_hoare(int *array_to_sort, size_t array_size);


#endif /* SORT_H */
