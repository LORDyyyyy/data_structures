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
    q->front = NULL;
    q->rear = NULL;
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
    queue_node_t* node = (queue_node_t*)malloc(sizeof(queue_node_t));

    if (!node)
        return;

    node->next = NULL;
    node->entry = e;

    if (!q->rear)
        q->front = node;
    else
        q->rear->next = node;
    q->rear = node;
    q->size++;
}


/**
 *  dequeue - delete the front of a queue
 *  @e: the value that will be removed
 *  @q: a pointer to the queue
*/
void dequeue(queue_entry* e, queue_t* q)
{
    queue_node_t* node = q->front;

    *e = node->entry;
    q->front = node->next;
    free(node);
    if (!q->front)
        q->rear = NULL;
    q->size--;
}


/**
 * queue_full - checks if the queue is full
 * @q: a pointer to the queue
 *
 * Return: always 0
 */
int queue_full(queue_t* q)
{
    return (0);
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
 * queue_front - get the front value of a queue
 * @q: a pointer to the queue
 *
 */
int queue_front(queue_t* q)
{
    return (q->front->entry);
}


/**
 * queue_size - gets a queue's size
 * @q: a pointer to the queue
 *
 * Return: the queue size
*/
int queue_size(queue_t* q)
{
    return (q->size);
}


/**
 * clear_queue - re init a queue
 * @q: a pointer to the queue
 *
 * Return: void
*/
void clear_queue(queue_t* q)
{
    while (q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }

    q->size = 0;
}


/**
 * traverse_queue - operate a function on a queue elemtens
 * @q: a pointer to the queue
 * @func: a pointer to a function
 *
 * Return: void
*/void traverse_queue(queue_t* q, void (*func)(queue_entry))
{
    for (queue_node_t* n = q->front; n; n = n->next)
        (*func)(n->entry);
}
