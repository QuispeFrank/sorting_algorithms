#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort
 * algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 *
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t index, undex, min_value, min_idx, change;

	for (index = 0; index < size - 1; index++)
	{
		change = 0;
		min_value = array[index];
		for (undex = index + 1; undex < size; undex++)
		{
			if (array[undex] < (int)min_value)
			{
				min_value = array[undex];
				min_idx = undex;
				change = 1;
			}
		}
		if (change == 1)
		{
			array[min_idx] = array[index];
			array[index] = min_value;
			print_array(array, size);
		}
	}
}
