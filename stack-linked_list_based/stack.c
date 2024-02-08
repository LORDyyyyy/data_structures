#include "stack.h"

/**
 * creat_stack - creats a stack
 * @s: a pointer to the stack
 *
 * Return: void
*/
void creat_stack(stack_t* s)
{
    s->top = NULL;
    s->size = 0;
}

/**
 * push - push an element to the top of the stack
 * @value: the value to add
 * @s: a pointer to the stack
 *
 * Return: 1 on success, 0 otherwise
*/
int push(int value, stack_t* s)
{
    stack_node_t* node = (stack_node_t*)malloc(sizeof(stack_node_t));

    if (!node)
        return (0);

    node->entry = value;
    node->next = s->top;
    s->top = node;
    s->size += 1;

    return (1);
}


/**
 * pop - deletes the top of a stack
 * e: element pointer
 * s: a pointer to the stack
 *
 * Return: 1 on success, 0 otherwise
*/
int pop(stack_entry* e, stack_t* s)
{
    stack_node_t* node;

    if (!s->top)
        return 0;

    *e = s->top->entry;
    node = s->top;
    s->top = s->top->next;
    free(node);
    s->size -= 1;

    return (1);
}

/**
 * stack_full - checks if the stack is full
 * @s: a pointer to the stack
 *
 * Return: always 0
*/
int stack_full(stack_t* s)
{
    return (0);
}


/**
 * stack_empty - checks is the stack is empty
 * @s: a pointer to the stack
 *
 * Return: 1 if empty, 0 otherwise
*/
int stack_empty(stack_t* s)
{
    return (s->top == NULL);
}


/**
 * stack_top - gets the top value of a stack
 * @s: a pointer to the stack
 * @e: element pointer
 *
 * Return: void
*/
void stack_top(stack_entry* e, stack_t* s)
{
    *e = s->top->entry;
}

/**
 * stack_size - gets a stack's size
 * @s: a pointer to the stack
 *
 * Return: the stack size
*/
int stack_size(stack_t* s)
{
    return (s->size);
}

/**
 * clear_stack - re init a stack
 * @s: a pointer to the stack
 *
 * Return: void
*/
void clear_stack(stack_t* s)
{
    stack_node_t* tmp1 = s->top;
    stack_node_t* tmp2 = s->top;

    while (tmp1)
    {
        tmp1 = tmp1->next;
        free(tmp2);
        tmp2 = tmp1;
    }
    s->size = 0;
    s->top = NULL;
}


/**
 * traverse_stack - operate a function on a stack
 * @s: a pointer to the stack
 * @func: a pointer to a function
 *
 * Return: void
*/
void traverse_stack(stack_t* s, void(*func)(stack_entry))
{
    stack_node_t* node = s->top;

    while (node)
    {
        (*func)(node->entry);
        node = node->next;
    }
}
