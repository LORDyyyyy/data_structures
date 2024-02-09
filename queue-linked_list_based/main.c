#include "queue.h"
#include <stdio.h>


int main(void)
{
	queue_t q;
	create_queue(&q);

	enqueue(1, &q);
	enqueue(2, &q);
	enqueue(3, &q);
	enqueue(4, &q);
	enqueue(5, &q);
    printf("front: %d\n", queue_front(&q));
	int y;
	dequeue(&y, &q);
    printf("front: %d\n", queue_front(&q));

    clear_queue(&q);

    return (0);
}
