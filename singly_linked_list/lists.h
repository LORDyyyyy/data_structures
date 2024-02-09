#ifndef LISTS
#define LISTS

#include <stdio.h>
#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */

#define LIST_TYPE int

typedef struct list_s
{
	LIST_TYPE n;
	struct list_s *next;
} list_t;


size_t print_list(const list_t *h);

size_t list_len(const list_t *h);

list_t *insert_at_end_list(list_t **head, const LIST_TYPE n);

void free_list(list_t **head);

list_t *get_at_index(list_t *head, unsigned int index);

list_t *insert_at_list(list_t **head, unsigned int idx, LIST_TYPE n);

int delete_at_list(list_t **head, unsigned int index);


#endif // LISTS
