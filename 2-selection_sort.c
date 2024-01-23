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
 * selection_sort - selection sort function
 * @array: pointer to array of integers
 * @size: size of array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
size_t min = 0, i = 0, j = 0;

for (i = 0; i < size; i++)
{
min = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min])
min = j;
}
if (i != min)
{
swap(&array[i], &array[min]);
print_array(array, size);
}
}
}
