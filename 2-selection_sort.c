#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, position;
	int swap;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[position])
				position = j;
		}
		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
			print_array(array, size);
		}
	}
}