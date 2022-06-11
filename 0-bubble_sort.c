#include "sort.h"

/**
 * bubble_sort - function that sorts an array of
 * integers in ascending order using the Bubble
 * sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, value, len = size;

	for (; size >= 2; size--)
	{
		for (index = 0; index < size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				value = array[index];
				array[index] = array[index + 1];
				array[index + 1] = value;
				print_array(array, len);
			}
		}
	}
}
