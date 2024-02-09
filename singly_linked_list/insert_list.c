#include "lists.h"

/**
 * insert_at_end_list - adds a new node at the end
 * @head: singly .......
 * @n: the value to add
 *
 * Return: new list
 */
list_t *insert_at_end_list(list_t **head, const LIST_TYPE n)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *tmp;

	if (!head || !new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}


/**
 * insert_at_list -  inserts a new node at a given position
 * @head: singly ....
 * @idx: index
 * @n: the value to add
 *
 * Return: list
 */
list_t *insert_at_list(list_t **head, unsigned int idx, LIST_TYPE n)
{
	list_t *node, *new = malloc(sizeof(list_t));
	unsigned int i = 0;

	if (!head || !new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	node = *head;
	while (node)
	{
		if (i == idx - 1)
		{
			new->next = node->next;
			node->next = new;
			return (new);
		}
		i++;
		node = node->next;
	}
	free(new);
	return (NULL);
}
