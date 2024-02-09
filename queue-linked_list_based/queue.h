#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>

#define queue_entry int

typedef struct queue_node_s {
    queue_entry entry;
    struct queue_node_s* next;
} queue_node_t;

typedef struct queue_s {
    queue_node_t* front;
    queue_node_t* rear;
    int size;
} queue_t;

void create_queue(queue_t* q);

void enqueue(queue_entry e, queue_t* q);
void dequeue(queue_entry* e, queue_t* q);

int queue_full(queue_t* q);
int queue_empty(queue_t* q);

int queue_front(queue_t* q);
int queue_size(queue_t* q);

void clear_queue(queue_t* q);

void traverse_queue(queue_t* q, void (*func)(queue_entry));


#endif // QUEUE
