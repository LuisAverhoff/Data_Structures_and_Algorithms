#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    int val, errCheck;
    Queue q;

    Queue_Init(&q, sizeof(int));

    for(val = 0; val < 10; val++)
    {
        errCheck = enqueue(&q, &val);

        if(errCheck)
        {
            printf("The value %d has been enqueued.\n", val + 1);
        }
        else
        {
            printf("Couldn't enqueue because of a memory failure. \n");
            printf("Freeing up resources and exiting.");
            Queue_Clear(&q);
            exit(EXIT_FAILURE);
        }
    }

    printf("\n");

    int *valPtr = Queue_Peek(&q);

    if(valPtr != NULL)
    {
        printf("The value that is at the front of the queue is %d\n\n", *valPtr + 1);
    }

    while(q.sizeOfQueue > 0)
    {
        dequeue(&q, &val);
        printf("%d has been dequeued.\n", val + 1);
    }

    printf("\nThe queue is now empty.\n");

    return 0;
}
