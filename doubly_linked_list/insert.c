#include "lists.h"


/**
 * add_node - adds a new node at the beginning of a dlist_t list
 * @head: doubly linked list
 * @n: data
 *
 * Return: dlist_t list
 */
dlist_t *add_node(dlist_t **head, const DLIST_TYPE n)
{
	dlist_t *temp = malloc(sizeof(dlist_t)), *h = *head;

	if (!temp)
		return (NULL);

	temp->n = n;
	temp->prev = NULL;
	temp->next = NULL;

	if (h)
		while (h->prev)
			h = h->prev;
	temp->next = h;
	if (h)
		h->prev = temp;

	*head = temp;
	return (temp);
}


/**
 * add_node_end - adds a new node at the end of a dlist_t list
 * @head: the list
 * @n: data to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlist_t *add_node_end(dlist_t **head, const DLIST_TYPE n)
{
	dlist_t *temp = malloc(sizeof(dlist_t)), *h = *head;

	if (!temp)
		return (NULL);

	temp->n = n;
	temp->next = NULL;
	temp->prev = NULL;

	if (h)
	{
		while (h->next)
			h = h->next;
		h->next = temp;
	}
	else
		*head = temp;
	temp->prev = h;

	return (temp);
}


/**
 * insert_node_at_index - inserts a new node at a given position
 * @h: the linked list
 * @n: the data to add
 * @idx: the wanted index to insert the new data
 * Return: the address of the new node
 */
dlist_t *insert_node_at_index(dlist_t **h, unsigned int idx, DLIST_TYPE n)
{
	dlist_t *tmp = NULL, *hh = *h;
	unsigned int count = 1;

	if (idx == 0)
	{
		tmp = add_node(h, n);
		return (tmp);
	}

	if (hh)
		while (hh->prev)
			hh = hh->prev;
	while (hh)
	{
		if (idx == count)
		{
			if (!hh->next)
				tmp = add_node_end(h, n);
			else
			{
				tmp = malloc(sizeof(dlist_t));
				if (!tmp)
					return (NULL);
				tmp->n = n;
				tmp->next = hh->next;
				tmp->prev = hh;
				hh->next->prev = tmp;
				hh->next = tmp;
			}
			break;
		}
		hh = hh->next;
		count++;
	}
	return (tmp);
}
