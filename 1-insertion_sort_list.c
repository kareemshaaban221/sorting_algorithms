#include "sort.h"

/**
 * swap - a and b
 * @a: the first element
 * @b: the second element
 * Return: void
*/
void swap(listint_t *a, listint_t *b)
{
    listint_t *nxtTmp = b->next;
    listint_t *preTmp = a->prev;

    printf("------------before swap-------------\n");
    printf("a: [%d]->[%d]->[%d]\nb: [%d]->[%d]->[%d]\n", a->prev ? a->prev->n : -1, a->n, a->next ? a->next->n : -1, b->prev ? b->prev->n : -1, b->n, b->next ? b->next->n : -1);
    if (preTmp)
        preTmp->next = b;
    if (nxtTmp)
        nxtTmp->prev = a;
    a->next = nxtTmp;
    a->prev = b;
    b->next = a;
    b->prev = preTmp;
    printf("------------after swap-------------\n");
    printf("a: [%d]->[%d]->[%d]\nb: [%d]->[%d]->[%d]\n", a->prev ? a->prev->n : -1, a->n, a->next ? a->next->n : -1, b->prev ? b->prev->n : -1, b->n, b->next ? b->next->n : -1);
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
            swap(k, j);
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
