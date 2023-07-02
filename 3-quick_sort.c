#include "sort.h"

void swap(int *x, int *y);
void quick_sort(int array[], size_t size);
void quicksort_recursion(int *array, size_t size, int low, int high);
size_t partition(int *array, size_t size, size_t low, size_t high);

/**
 * swap - a function to swap elements
 * @x: the first element
 * @y: the second element
 * Return: nothing
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * quick_sort - a frame function to call the quicksort recursion function
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, size, 0, size - 1);
}

/**
 * quicksort_recursion - a recursion function for the quick sort
 * @array: the size of the array
 * @size: the size of the array
 * @low: the starting point of the loop
 * @high: the end point od the array
 *
 * Return: nothing
 */

void quicksort_recursion(int *array, size_t size, int low, int high)
{
	if (size < 2 || array == NULL)
		return;

	if (low < high)
	{
		int pivot_index = partition(array, size, low, high);

		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * partition - the function to partition the array
 * @array: the array to partition
 * @size: the size of the array
 * @low: the low point of the partitioned array
 * @high: the high point of the partitioned array
 *
 * Return: the position of the last swapped element .previous pivot
 */

size_t partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot_value = array[high];

	size_t j, i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, size);
	return (i);
}