#include "sort.h"

/**
 * swap - swaps two integers.
 * @arg1: first integer
 * @arg2: second integer
 *
 * Return: nothing.
 */
void swap(int *arg1, int *arg2)
{
	int value;

	value = *arg1;
	*arg1 = *arg2;
	*arg2 = value;
}

/**
 * Partition - partitions an array in 2 subarray
 * through pivot index.
 *
 * @A: the given array
 * @start: start index.
 * @end: end index.
 * @size: the size of the array.
 *
 * Return: the pivot index.
 */
int Partition(int *A, int start, int end, size_t size)
{
	int pivot = A[end], pIndex = start - 1, i;

	for (i = start; i <= end; i++)
	{
		if (A[i] <= pivot)
		{
			pIndex++;
			swap(&A[pIndex], &A[i]);
			if (pIndex != i)
				print_array(A, size);
		}
	}
	return (pIndex);
}

/**
 * QuickSort - sorts recursively an array of integers.
 * @A: array of integers to be sorted.
 * @start: start index.
 * @end: end index.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void QuickSort(int *A, int start, int end, size_t size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = Partition(A, start, end, size);
		QuickSort(A, start, pIndex - 1, size);
		QuickSort(A, pIndex + 1, end, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: array of integers to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	QuickSort(array, 0, size - 1, size);
}
