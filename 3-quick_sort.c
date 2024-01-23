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
 * 
*/
size_t lomuto_partition(int *array, size_t l, size_t h, size_t size)
{
    size_t p = h, i = l, j = l;

    // printf("%d\n", array[p]);
    while (i < h) {
        if (array[i] >= array[p]);
        else
        {
            if (array[i] != array[j])
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            j++;
        }
        i++;
    }
    if (array[j] != array[p])
    {
        swap(&array[j], &array[p]);
        print_array(array, size);
    }
    p = j;
    // printf("%d\n", array[p]);
    return p;
}

/**
 * 
*/
void quick_sort_recursive(int *array, size_t l, size_t h, size_t size)
{
    size_t p = 0;
    // printf("l: %d, h: %d\n", l, h);

    if (l >= h)
        return;
    p = lomuto_partition(array, l, h, size);
    // printf("right\n");
    quick_sort_recursive(array, p + 1, h, size);
    // printf("left\n");
    if (p > 0)
        quick_sort_recursive(array, l, p - 1, size);
}

/**
 * quick_sort - quick sort
 * @array: array of integers
 * @size: number of elements
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
    if (size == 1)
        return;
    quick_sort_recursive(array, 0, size - 1, size);
}
