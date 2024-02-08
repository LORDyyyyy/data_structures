#include "stack.h"

/**
 * create_stack - initialize a stack
 * @s: a pointer to the stack
 *
 * Return: void
*/
void create_stack(stack_t* s)
{
    s->top = 0;
}

/**
 * push - push an element to the top of the stack
 * value: the value to push
 * s: a pointer to the stack
 *
 * Return: 1 on success, 0 otherwise
*/
int push(int value, stack_t* s)
{
    if (s->top == MAX_SIZE)
        return (0);

    s->entry[s->top++] = value;

    return (1);
}


/**
 * pop - deletes the top of a stack
 * @e: element pointer, to retrive the popped element
 * @s: a pointer to the stack
 *
 * Return: 1 on success, 0 otherwise
*/
int pop(STACK_ENTRY* e, stack_t* s)
{
    if (s->top == 0)
        return (0);
    *e = s->entry[--s->top];

    return (1);
}

/**
 * stack_full - checks if the stack is full
 * @s: a pointer to the stack
 *
 * Return: 1 if full, 0 otherwise
*/
int stack_full(stack_t* s)
{
    return (s->top == MAX_SIZE);
}


/**
 * stack_empty - checks is the stack is empty
 * @s: a pointer to the stack
 *
 * Return: 1 if empty, 0 otherwise
*/
int stack_empty(stack_t* s)
{
    return (s->top == 0);
}


/**
 * stack_top - gets the top value of a stack
 * @s: a pointer to the stack
 * @e: element pointer, to retrive the top
 *
 * Return: void
*/
void stack_top(STACK_ENTRY* e, stack_t* s)
{
    *e = s->entry[s->top - 1];
}

/**
 * stack_size - gets a stack's size
 * @s: a pointer to the stack
 *
 * Return: the stack size
*/
int stack_size(stack_t* s)
{
    return (s->top);
}

/**
 * clear_stack - re init a stack
 * @s: a pointer to the stack
 *
 * Return: void
*/
void clear_stack(stack_t* s)
{
    s->top = 0;
}


/**
 * traverse_stack - operate a function on a stack elemtens
 * @s: a pointer to the stack
 * @func: a pointer to a function
 *
 * Return: void
*/
void traverse_stack(stack_t* s, void(*func)(STACK_ENTRY))
{
    int i;

    if (!func)
        return;

    for (i = s->top; i > 0; i--)
        (*func)(s->entry[i - 1]);
}
