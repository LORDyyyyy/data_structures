#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlist_t *head;

	head = NULL;
	add_node_end(&head, 0);
	add_node_end(&head, 1);
	add_node_end(&head, 2);
	add_node_end(&head, 3);
	add_node_end(&head, 4);
	add_node_end(&head, 98);
	add_node_end(&head, 402);
	add_node_end(&head, 1024);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 999);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 0);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 0);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 0);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 0);
	print_dlist(head);
	printf("-----------------\n");
	delete_node_at_index(&head, 0);
	print_dlist(head);
	free_dlist(head);
	head = NULL;
	insert_node_at_index(&head, 0, 100);
	insert_node_at_index(&head, 1, 300);
	insert_node_at_index(&head, 1, 200);

	printf("-----------------\n");
	print_dlist(head);

	free_dlist(head);
	return (0);
}
