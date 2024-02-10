#ifndef LISTS
#define LISTS

#include <stdio.h>
#include <stdlib.h>

#define DLIST_TYPE int


/**
 * struct dlist_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlist_s
{
	DLIST_TYPE n;
	struct dlist_s *prev;
	struct dlist_s *next;
} dlist_t;


size_t print_dlist(const dlist_t *h);

size_t dlist_len(const dlist_t *h);

dlist_t *add_node(dlist_t **head, const DLIST_TYPE n);
dlist_t *add_node_end(dlist_t **head, const DLIST_TYPE n);
dlist_t *insert_node_at_index(dlist_t **h, unsigned int idx, DLIST_TYPE n);

void free_dlist(dlist_t *head);

dlist_t *get_node_at_index(dlist_t *head, unsigned int index);

int delete_node_at_index(dlist_t **head, unsigned int index);

#endif
