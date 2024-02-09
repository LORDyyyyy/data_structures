#include "lists.h"

/**
 * print_list -  prints all the elements of a list_t list
 * @h: singly double list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}

	return (len);
}

