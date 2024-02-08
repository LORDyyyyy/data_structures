#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>


#define stack_entry int

typedef struct stack_node_s
{
    stack_entry entry;
    struct stack_node_s* next;
} stack_node_t;

typedef struct stack {
    stack_node_t* top;
    int size;
} stack_t;

void creat_stack(stack_t* s);

int push(int value, stack_t* s);
int pop(stack_entry* e, stack_t* s);

int stack_full(stack_t* s);
int stack_empty(stack_t* s);

int stack_size(stack_t* s);

void clear_stack(stack_t* s);

void traverse_stack(stack_t* s, void(*func)(stack_entry));

#endif // STACK
