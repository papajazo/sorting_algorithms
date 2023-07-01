#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: an array of integers
 * @size: side of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t minimum, r, c;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (r = 0; c < size - 1; r++)
	{
		minimum = r;
		for (c = r + 1; c < size; c++)
		{
			if (array[c] < array[minimum])
				minimum = c;
		}
		if (r != minimum)
		{
			swap = array[r];
			array[r] = array[minimum];
			array[minimum] = swap;
			print_array(array, size);
		}
	}
}
