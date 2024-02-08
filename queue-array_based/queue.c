#include "queue.h"


/**
 *  create_queue - init a queue
 *  @q: a pointer to q
 *
 *  Return: void
*/
void create_queue(queue_t* q)
{
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

/**
 *  enqueue - append an element to a queue
 *  @e: the value to enqueue
 *  @q: a pointer to the queue
 *
 *  Return: void
*/
void enqueue(queue_entry e, queue_t* q)
{
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->entry[q->rear] = e;
    q->size++;
}


/**
 *  dequeue - delete the front of a queue
 *  @e: the value that will be removed
 *  @q: a pointer to the queue
*/
void dequeue(queue_entry* e, queue_t* q)
{
    *e = q->entry[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
}


/**
 * queue_full - checks if the queue is full
 * @q: a pointer to the queue
 *
 * Return: 1 if full, 0 otherwise
*/int queue_full(queue_t* q)
{
    return (q->size == MAX_SIZE);
}


/**
 * queue_empty - checks is the queue is empty
 * @q: a pointer to the queue
 *
 * Return: 1 if empty, 0 otherwise
*/
int queue_empty(queue_t* q)
{
    return (q->size == 0);
}


/**
 * queue_size - gets a queue's size
 * @s: a pointer to the queue
 *
 * Return: the queue size
*/
int queue_size(queue_t* q)
{
    return (q->size);
}


int queue_front(queue_t* q)
{
    return (q->entry[q->front]);
}


/**
 * clear_queue - re init a queue
 * @s: a pointer to the queue
 *
 * Return: void
*/
void clear_queue(queue_t* q)
{
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}


/**
 * traverse_queue - operate a function on a queue elemtens
 * @q: a pointer to the queue
 * @func: a pointer to a function
 *
 * Return: void
*/
void traverse_queue(queue_t* q, void (*func)(queue_entry))
{
    int i, s;

    for (i = q->front, s = 0; s < q->size; s++)
    {
        (*func)(q->entry[i]);
        i = (i + 1) % MAX_SIZE;
    }
}
