#include "stack.h"

int main(void)
{
    stack_entry e;
    stack_t s;

    creat_stack(&s);

    push(1, &s);
    push(2, &s);
    push(3, &s);
    push(4, &s);
	push(5, &s);
	push(6, &s);

	putchar(10);

    clear_stack(&s);
	return (0);
}
