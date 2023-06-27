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
/**
 * swap_array_element - swaps two elements of an array
 *
 * @m: the first pointer
 * @n: the second pointer
 */
void swap_array_element(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}
