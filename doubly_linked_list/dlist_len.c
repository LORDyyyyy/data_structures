#include "lists.h"

/**
 * dlist_len -  returns the number of elements in a linked dlist_t list
 * @h: the head of a d linked list
 *
 * Return: @h size
 */
size_t dlist_len(const dlist_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h->prev)
		h = h->prev;
	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
