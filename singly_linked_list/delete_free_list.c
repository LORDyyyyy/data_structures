#include "lists.h"

/**
 * delete_at_list -  deletes the node at index index of a list_t
 * @head: list
 * @index: index
 *
 * Return: 1 on success, -1 otherwise
 */
int delete_at_list(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node);
			return (1);
		}
		i++;
		prev_node =  node;
		node = node->next;
	}
	return (-1);
}


/**
 * free_list - frees a list
 * @head: singly ....
 * Return: void
 */
void free_list(list_t **head)
{
	list_t *node, *tmp;

	if (!head)
		return;
	node = *head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*head = NULL;
}

