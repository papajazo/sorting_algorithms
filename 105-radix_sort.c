#include "sort.h"

int max_val(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * max_val - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_val(int *array, int size)
{
	int max, r;

	for (max = array[0], r = 1; r < size; r++)
	{
		if (array[r] > max)
			max = array[r];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t r;

	for (r = 0; r < size; r++)
		count[(array[r] / sig) % 10] += 1;

	for (r = 0; r < 10; r++)
		count[r] += count[r - 1];

	for (r = size - 1; (int)r >= 0; r--)
	{
		buff[count[(array[r] / sig) % 10] - 1] = array[r];
		count[(array[r] / sig) % 10] -= 1;
	}

	for (r = 0; r < size; r++)
		array[r] = buff[r];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = max_val(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
