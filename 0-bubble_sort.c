#include "sort.h"

/**
 * swap - swaping two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * Return: void
*/
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bubble_sort - implementation of bubble sort
 * @array: unsorted array
 * @size: array size
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;

while (i < size)
{
for (j = 0; j < size - i - 1; j++)
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);
print_array(array, size);
}
i++;
}
}
