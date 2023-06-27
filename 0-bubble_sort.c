#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order,
 * using the Buble sort algorithm
 *
 * @array: array to be sorted
 * @size: number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int r, sorted_array = 0;

	if (size < 2)
		return;

	while (sorted_array == 0)
	{
		sorted_array = 1;
		for (r = 0; r < (size - 1); r++)
		{
			if (array[r] > array[r + 1])
			{
				swap_array_element(&array[r], &array[r + 1]);
				print_array(array, size);
				sorted_array = 0;
			}
		}
	}
}

/*
 * swap_array_element - swaps two elements of @array
 *
 * @m: first element
 * @n: second element
 */
void swap_array_element(int *m, int *n)
{
	int o = 0;

	o = *m;
	*m = *n;
	*n = o;
}
