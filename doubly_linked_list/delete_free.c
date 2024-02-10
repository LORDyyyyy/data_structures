#include "lists.h"

/**
 * free_dlist - frees a dlist_t list
 * @head: the head of the list
 */
void free_dlist(dlist_t *head)
{
	dlist_t *tmp;

	if (!head)
		return;

	while (head->prev)
		head = head->prev;
	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
	head = NULL;
}


/**
 * delete_node_at_index -  deletes the node at index
 * @head: the linked list
 * @index: thw wanted index to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_node_at_index(dlist_t **head, unsigned int index)
{
	dlist_t *tmp_1, *tmp_2;
	unsigned int count = 0;

	tmp_1 = *head;

	if (tmp_1)
		while (tmp_1->prev)
			tmp_1 = tmp_1->prev;

	while (tmp_1)
	{
		if (index == count)
		{
			if (index == 0)
			{
				*head = tmp_1->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				tmp_2->next = tmp_1->next;
				if (tmp_1->next)
					tmp_1->next->prev = tmp_2;
			}
			free(tmp_1);
			return (1);
		}
		tmp_2 = tmp_1;
		tmp_1 = tmp_1->next;
		count++;
	}
	return (-1);
}
