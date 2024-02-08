#ifndef QUEUE
#define QUEUE

#include <stdio.h>

#define MAX_SIZE 10
#define queue_entry int

typedef struct queue_s {
    int front;
    int rear;
    int size;
    queue_entry entry[MAX_SIZE];
} queue_t;

void create_queue(queue_t* q);

void enqueue(queue_entry e, queue_t* q);
void dequeue(queue_entry* e, queue_t* q);

int queue_front(queue_t* q);

int queue_full(queue_t* q);
int queue_empty(queue_t* q);
int queue_size(queue_t* q);

void clear_queue(queue_t* q);

void traverse_queue(queue_t* q, void (*func)(queue_entry));


#endif // QUEUE
