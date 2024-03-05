#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending using Bubble Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t idx_outer, idx_inner;
	int temp_value;
	int has_swapped;

	for (idx_outer = 0; idx_outer < size - 1; ++idx_outer)
	{
		has_swapped = 0;
		for (idx_inner = 0; idx_inner < size - idx_outer - 1; ++idx_inner)
		{
			if (array[idx_inner] > array[idx_inner + 1])
			{
				/*Swap array[idx_inner] and array[idx_inner + 1]*/
				temp_value = array[idx_inner];
				array[idx_inner] = array[idx_inner + 1];
				array[idx_inner + 1] = temp_value;
				has_swapped = 1;

				/*Print the array after each swap*/
				print_array(array, size);
			}
		}

		if (has_swapped == 0)
			break;
	}
}
