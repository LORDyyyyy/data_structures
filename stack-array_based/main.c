#include "stack.h"
#include <stdio.h>




/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{

	stack_t s;
	create_stack(&s);

	push(1, &s);
	push(2, &s);
	push(3, &s);
	push(4, &s);
	push(5, &s);
	
	int temp;

	pop(&temp, &s);
	putchar(10);
    return (0);
}



