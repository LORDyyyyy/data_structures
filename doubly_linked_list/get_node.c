#include "lists.h"

/**
 * get_node_at_index - returns the nth node of a dlist_t linked list
 * @head: the head of a linked list
 * @index: wanted index
 *
 * Return: the node, if the node does not exist, return NULL
 */
dlist_t *get_node_at_index(dlist_t *head, unsigned int index)
{
	size_t len = dlist_len(head);
	unsigned int count = 0;
	dlist_t *tmp = malloc(sizeof(dlist_t));

	if (index >= len)
		return (NULL);

	if (!head)
		return (NULL);

	while (head->prev)
		head = head->prev;

	while ((tmp = head))
	{
		if (index == count)
			return (tmp);
		head = head->next;
		count++;
	}
	return (NULL);
}
