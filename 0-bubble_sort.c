#include "sort.h"

/**
 * bubble_sort - function sorts data using the bubble sort algorithm
 * @array: array of data to be sorted
 * @size: an unsigned int
 *
 * Return: nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL)
		return;

	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
