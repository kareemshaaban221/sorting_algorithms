#include "sort.h"

/**
 * swap - a and b
 * @a: the first element
 * @b: the second element
 * Return: void
*/
void swap(listint_t *a, listint_t *b, listint_t **list)
{
    listint_t *nxtTmp = b->next;
    listint_t *preTmp = a->prev;

    if (preTmp)
        preTmp->next = b;
    else
        *list = b;
    if (nxtTmp)
        nxtTmp->prev = a;
    a->next = nxtTmp;
    a->prev = b;
    b->next = a;
    b->prev = preTmp;
}

/**
 * insertion_sort_list - insertion sort list
 * @list: insertion sort list
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *i = *list, *j = NULL, *k = NULL, *tmp = NULL;
    short firstIteration = 1;

    if (!list)
        return;

    while (i)
    {
        k = i->prev;
        j = i;
        while (k && k->n > j->n)
        {
            swap(k, j, list);
            if (firstIteration)
            {
                i = k;
                firstIteration = 0;
            }
            tmp = k;
            k = j;
            j = tmp;
            j = j->prev;
            k = k->prev;
            print_list(*list);
        }
        firstIteration = 1;
        i = i->next;
    }
}
