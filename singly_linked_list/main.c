#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;
    int n;

    head = NULL;
    insert_at_end_list(&head, 0);
    insert_at_end_list(&head, 1);
    insert_at_end_list(&head, 2);
    insert_at_end_list(&head, 3);
    insert_at_end_list(&head, 4);
    insert_at_end_list(&head, 98);
    insert_at_end_list(&head, 402);
    insert_at_end_list(&head, 1024);
    print_list(head);

    n = get_at_index(head, 0)->n;

    delete_at_list(&head, 0);
    printf("- %d\n", n);
    print_list(head);
    
    n = get_at_index(head, 0)->n;

    delete_at_list(&head, 0);
    printf("- %d\n", n);
    print_list(head);
    
    free_list(&head);
    
    printf("%p\n", (void *)head);

    return (0);
}
