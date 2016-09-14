#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Node node;

typedef struct QueueList
{
    size_t sizeOfQueue;
    size_t memSize;
    node *head;
    node *tail;
}Queue;

void Queue_Init(Queue *q, size_t memSize); /*Initializes the Queue with its default values.*/
int enqueue(Queue *, const void *); /*Push the element to the end of the queue.*/
void dequeue(Queue *, void *); /*Pops the last element that entered the queue.*/
void *Queue_Peek(const Queue *); /*Reads the element that is at the end of the Queue.*/
void Queue_Clear(Queue *); /*Removes all the elements in the Queues*/
int isQueueEmpty(const Queue *); /*Checks if the Queue is empty.*/
int Queue_GetSize(const Queue *); /*Returns the current size of the Queue.*/

#endif
