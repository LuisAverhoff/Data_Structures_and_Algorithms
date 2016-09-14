#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queue.h"

struct Node
{
    void *data;
    struct Node *next;
};

void Queue_Init(Queue *q, size_t memSize)
{
    /*Does not make sense to create a queue with each element having a memory size of 0*/
    if(q->memSize != 0)
    {
        q->sizeOfQueue = 0;
        q->memSize = memSize;
        q->head = q->tail = NULL;
    }
}

int enqueue(Queue *q, const void *data)
{
    node *newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL)
    {
        return false;
    }

    newNode->data = malloc(q->memSize);

    if(newNode->data == NULL)
    {
        free(newNode);
        return false;
    }

    newNode->next = NULL;

    memcpy(newNode->data, data, q->memSize);

    if(isQueueEmpty(q))
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->sizeOfQueue++;
    return true;
}

void dequeue(Queue *q, void *data)
{
    if(!isQueueEmpty(q))
    {
        node *temp = q->head;
        memcpy(data, temp->data, q->memSize);

        if(q->sizeOfQueue > 1)
        {
            q->head = q->head->next;
        }
        else
        {
            q->head = NULL;
            q->tail = NULL;
        }

        q->sizeOfQueue--;
        free(temp->data);
        free(temp);
    }
}

void  *Queue_Peek(const Queue *q)
{
    if(!isQueueEmpty(q))
    {
        return q->head->data;
    }

    return NULL;
}

void Queue_Clear(Queue *q)
{
    if(!isQueueEmpty(q))
    {
        node *temp;

        while(!isQueueEmpty(q))
        {
            temp = q->head;
            q->head = temp->next;
            free(temp->data);
            free(temp);
            q->sizeOfQueue--;
        }

        q->head = q->tail = NULL;
        q->memSize = 0;
    }

}

int isQueueEmpty(const Queue *q)
{
    return (q->sizeOfQueue == 0) ? 1 : 0;
}

int Queue_GetSize(const Queue *q)
{
    return q->sizeOfQueue;
}
