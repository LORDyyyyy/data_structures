#include "lists.h"

/**
 * get_at_index - returns the nth node of a list_t linked list
 * @head: singly .......
 * @index: index
 *
 * Return: nth node of head
 */
list_t *get_at_index(list_t *head, unsigned int index)
{
	list_t *tmp;
	unsigned int n;

	for (tmp = head, n = 0; tmp && n < index; tmp = tmp->next, n++)
		;
	return (tmp);
}
