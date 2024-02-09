#include "lists.h"

/**
 * list_len - returns the number of elements in a linked
 * @h: singly linked list
 *
 * Return: len of h
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
