#ifndef STACK
#define STACK

#include <stdio.h>


#define MAX_SIZE 100
#define STACK_ENTRY int


typedef struct stack_s
{
    int top;
    int size;
    STACK_ENTRY entry[MAX_SIZE];
} stack_t;


void create_stack(stack_t* s);

int push(int value, stack_t* s);
int pop(STACK_ENTRY* e, stack_t* s);

int stack_full(stack_t* s);
int stack_empty(stack_t* s);

void stack_top(STACK_ENTRY* e, stack_t* s);
int stack_size(stack_t* s);

void clear_stack(stack_t* s);

void traverse_stack(stack_t* s, void(*func)(STACK_ENTRY));


#endif // STACK
